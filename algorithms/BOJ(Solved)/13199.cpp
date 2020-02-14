/*
치킨 먹고 싶다
https://www.acmicpc.net/problem/13199
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t, p, m, f, c;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> p >> m >> f >> c;
		ll coupon = (m / p) * c;
		if (coupon < f) cout << 0 << '\n';
		else cout << ((coupon - f) / (f - c) + 1) - (coupon / f) << '\n';
	}
}
