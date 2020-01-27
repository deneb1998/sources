/*
이항 계수 4
https://www.acmicpc.net/problem/11402
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

ll n, k, m, ans = 1;
vector<ll> v1, v2;
ll dp[2005][2005];

ll calc(ll x, ll y) {
	if (dp[x][y])
		return dp[x][y];
	if (!y || x == y)
		return 1;
	if (y > x - y)
		return dp[x][y] = calc(x, x - y);
	return dp[x][y] = calc(x - 1, y - 1) + calc(x - 1, y);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k >> m;
	while (n) {
		v1.push_back(n % m);
		n /= m;
	}
	while (k) {
		v2.push_back(k % m);
		k /= m;
	}
	int i, len = v1.size(), len2 = v2.size();
	for (i = 0; i < len; i++) {
		if (len2 - 1 < i)
			continue;
		ans *= calc(v1[i], v2[i]);
		ans %= m;
	}
	cout << ans;
}
