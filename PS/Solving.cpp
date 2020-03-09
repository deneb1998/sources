#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, x;
vector<int> dp[510][510];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	m = 2 * n - 1;
	int i, j, k;
	for (i = 1; i <= m; i++) {
		cin >> x;
		bool check[510][510] = { false, };
		if (dp[1][x].empty()) {
			dp[1][x].push_back(x);
			check[1][x] = true;
		}
		for (j = 2; j <= i && j <= n; j++) { //j개
			for (k = 0; k < n; k++) { //k를 만들수있나
				if (!dp[j][(k + x) % n].empty()) continue;
				if (!dp[j - 1][k].empty() && !check[j - 1][k]) {
					dp[j][(k + x) % n] = dp[j - 1][k];
					dp[j][(k + x) % n].push_back(x);
					check[j][(k + x) % n] = true;
					if (j == n && (k + x) % n == 0) {
						for (auto it : dp[j][(k + x) % n])
							cout << it << ' ';
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
}
