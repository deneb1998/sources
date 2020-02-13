/*
치킨 먹고 싶다
https://www.acmicpc.net/problem/13199
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int t, p, m, f, c;

pair<ll, ll> func(ll coupon) {
	if (!(coupon / f))
		return make_pair(0LL, coupon);
	bool is = false;
	if (((coupon % f) + ((coupon / f) * c)) >= f)
		is = true;
	if(is)
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> p >> m >> f >> c;
		ll coupon = (m / p) * c;
		ll ans = 0, i = 0;
		while (1) {
			if (coupon / f) {
				i++;
				ans += coupon / f;
				coupon = (coupon % f) + ((coupon / f) * c);
			}
			else {
				cout << ans << '\n';
				break;
			}
		}
	}
}
