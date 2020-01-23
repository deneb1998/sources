/*
전깃줄
https://www.acmicpc.net/problem/2565
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, ans;
pair<int, int> line[510];
int dp[510];

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int i, j, a, b;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		line[i] = make_pair(a, b);
	}
	sort(line, line+n, compare);

	dp[n - 1] = ans = 1;
	for (i = n - 2; i >= 0; i--) {
		int max_ = 0;
		for (j = i + 1; j < n; j++) {
			if (line[j].second > line[i].second && max_ < dp[j])
				max_ = dp[j];
		}
		dp[i] = 1 + max_;
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << n - ans;
}

