/*
14501 Επ»η
https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, t[15], p[15], dp[16];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);

	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &p[i]);
		dp[i] = 0;
	}
	
	if (t[n - 1] == 1)
		dp[n - 1] = p[n - 1];
	for (i = n - 2; i >= 0; i--) {
		if (i + t[i] > n)
			dp[i] = dp[i + 1];
		else 
			dp[i] = max(p[i] + dp[i + t[i]], dp[i + 1]);
	}
	cout << dp[0];
}