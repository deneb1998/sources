/*
ภüฑ๊มู
https://www.acmicpc.net/problem/2565
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, result, ans;
int dp[500010][2];
pair<int, int> line[100010];
vector<int> v;
struct node {
	int val;
	int i;
};
map<int, node> m;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int i, j, a, b;
	map<int, node>::iterator it;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		line[i] = make_pair(a, b);
	}
	sort(line, line+n, compare);

	dp[n - 1][0] = result = 1;
	dp[n - 1][1] = -1;
	m.insert(line[n - 1].second, node{ 1, n - 1 });
	ans = n - 1;

	for (i = n - 2; i >= 0; i--) {
		it = m.lower_bound(line[i].second);
		dp[i][0] = 1 + it->second;
		dp[i][1] = it->first;

		if (dp[i][0] > result) {
			result = dp[i][0];
			ans = i;
		}
	}
	int x = ans;
	while (x != -1) {
		x = dp[x][1];
		v.push_back(x);
	}
	cout << n - result << '\n';
	for (i = 0; i < ans; i++) {
		cout << line[i].first << '\n';
	}
	int cnt = 0;
	for (i = ans + 1; i < n; i++) {
		if (v[cnt] == i) {
			cnt++;
			continue;
		}
		cout << line[i].first << '\n';
	}
}

