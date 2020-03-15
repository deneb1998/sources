/*
Hashing
https://www.acmicpc.net/problem/15829
*/
#include <bits/stdc++.h>
#define INF ((1<<31) - 1)
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
#define M 1234567891

int l;
ll h;
string s;

ll mysqrt(int n) {
	ll ret = 1;
	while (n--) {
		ret *= 31;
		ret %= M;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> l >> s;
	int i;
	for (i = 0; i < l; i++) {
		ll x = s[i] - 'a' + 1;
		x = x * mysqrt(i);
		h += x;
		h %= M;
	}
	cout << h;
}
