/*
파티
https://www.acmicpc.net/problem/2367
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e+10
using namespace std;

int n, k, d, ans, flow[305][305], level[305], E;
vector<pair<int, int> > edge[305];

void make_edge(int s, int e, int c) {
	edge[s].emplace_back(e, c);
	edge[e].emplace_back(s, 0);
}

bool leveling() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(0);
	level[0] = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto i : edge[x]) {
			int to = i.first, cap = i.second;
			if (level[to] == -1 && cap - flow[x][to] > 0) {
				level[to] = level[x] + 1;
				q.push(to);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int x, int sum) {
	if (x == E)
		return sum;
	for (auto i : edge[x]) {
		int to = i.first, cap = i.second;
		if (level[to] != level[x] + 1 || cap - flow[x][to] == 0)
			continue;
		int c = dfs(to, min(sum, cap - flow[x][to]));
		if (c > 0) {
			flow[x][to] += c;
			flow[to][x] -= c;
			return c;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> d;
	E = n + d + 1;
	int i, j;
	for (i = 1; i <= d; i++) {
		cin >> j;
		make_edge(n + i, E, j);
	}
	for (i = 1; i <= n; i++) {
		make_edge(0, i, k);
		cin >> j;
		while (j--) {
			int x;
			cin >> x;
			make_edge(i, n + x, 1);
		}
	}
	while (leveling()) {
		while (1) {
			int tmp = dfs(0, INF);
			if (!tmp) break;
			ans += tmp;
		}
	}

	cout << ans;
}
