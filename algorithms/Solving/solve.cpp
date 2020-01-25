/*
Àü±êÁÙ - 2
https://www.acmicpc.net/problem/2568
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
bool check[100010] = { false, };
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
	sort(line, line + n, compare);

	dp[n - 1][0] = result = 1;
	dp[n - 1][1] = -1;
	m.insert(make_pair(line[n - 1].second, node{ 1, n - 1 }));
	ans = n - 1;

	for (i = n - 2; i >= 0; i--) {
		it = m.lower_bound(line[i].second);
		if (it == m.end()) {
			dp[i][0] = 1;
			dp[i][1] = -1;
		}
		else {
			dp[i][0] = 1 + (it->second).val;
			dp[i][1] = (it->second).i;
		}
		m.insert(make_pair(line[i].second, node{ dp[i][0], i }));

		if (dp[i][0] > result) {
			result = dp[i][0];
			ans = i;
		}
	}
	cout << n - result << '\n';

	int x = ans;
	while (x != -1) {
		check[x] = true;
		x = dp[x][1];
	}

	for (i = 0; i < n; i++) {
		if (check[i]) continue;
		cout << line[i].first << '\n';
	}
}

/* ¹İ·Ê
0 1 2 3 4 5   6 7 8 9
6 8 2 9 5 10  4 1 7 3
*/