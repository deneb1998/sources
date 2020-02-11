/*
그룹 나누기
https://www.acmicpc.net/problem/16132
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, sum[51];
ll dp[51][1276];

int main() {
	int i, j;
	cin >> n;
	for (i = 1; i < 51; i++)
		sum[i] = sum[i - 1] + i;
	if (sum[n] % 2) {
		cout << 0;
		return 0;
	}

	dp[1][1] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= sum[i]; j++) {
			if (i == j) dp[i][j]++;
			if (j <= sum[i - 1])
				dp[i][j] += dp[i - 1][j];
			if (j > i)
				dp[i][j] += dp[i - 1][j - i];
		}
	}
	cout << dp[n][sum[n] / 2] / 2;
}
