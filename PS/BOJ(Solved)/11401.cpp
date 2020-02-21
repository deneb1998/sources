/*
이항 계수 3
https://www.acmicpc.net/problem/11401
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
typedef long long ll;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define P 1000000007LL
using namespace std;

int n, k;
ll fac[4000009], ans, inv[4000009];

ll power(ll x, ll y) {
	ll ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int i;
	fac[1] = 1;
	for (i = 2; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P;
	inv[4000000] = power(fac[4000000], P - 2);
	for (i = 3999999; i > 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P;

	cin >> n >> k;

	if (!k || n == k) {
		cout << 1;
		return 0;
	}

	ans = (fac[n] * inv[n - k]) % P;
	ans = (ans * inv[k]) % P;
	cout << ans;
}
