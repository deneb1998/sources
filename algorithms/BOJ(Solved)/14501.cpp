/*
14501 퇴사
https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, t[20], p[20], dp[20];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);

	int i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		dp[i] = 0;
	}

	for (i = n; i > 0; i--) {
		if (i + t[i] > n + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(p[i] + dp[i + t[i]], dp[i + 1]);
	}
	cout << dp[1] << endl;
	return 0;
}
