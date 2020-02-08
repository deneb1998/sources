/*
최대공약수
https://www.acmicpc.net/problem/1850
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
typedef long long ll;
using namespace std;

ll a, b;

ll gcd(ll x, ll y) {
	if (y > x) swap(x, y);
	ll tmp;
	while (x % y) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b;
	ll i = gcd(a, b);
	while (i--)
		cout << '1';
	return 0;
}
