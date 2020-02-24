/*
토렌트
https://www.acmicpc.net/problem/9577
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define INF ((1<<31) - 1)
using namespace std;

int t, n, m, a, b, c, x, level[205], ans, cap[205][205], flow[205][205], can[105][105], maxT;

vector<int> edge[205];

bool leveling() {
	memset(level, -1, sizeof(level));
	level[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : edge[now]) {
			if (level[i] != -1 || cap[now][i] <= flow[now][i])
				continue;
			level[i] = level[now] + 1;
			q.push(i);
		}
	}
	return (level[maxT + n + 1] != -1);
}

bool dinic(int maxT) {
	memset(flow, 0, sizeof(flow));
	while (leveling()) {

	}
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(cap, 0, sizeof(cap));
		memset(can, -1, sizeof(can));

		cin >> n >> m;
		maxT = -1;
		int i, j;
		while (m--) {
			cin >> a >> b >> c;
			if (a == b) continue;
			maxT = max(maxT, b);
			while (c--) {
				cin >> x;
				for (i = a + 1; i <= b; i++)
					can[i][x] = 1;
			}
		}
		for (i = 1; i <= maxT; i++) {
			edge[0].push_back(i);
			cap[0][i] = 1;
			for (j = 1; j <= n; j++) {
				if (can[i][j] != 1)
					continue;
				edge[i].push_back(maxT + j);
				cap[i][maxT + j] = 1;
			}
		}
		for (i = maxT + 1; i <= maxT + n; i++) {
			edge[i].push_back(maxT + n + 1);
			cap[i][maxT + n + 1] = 1;
		}
		if (!dinic(maxT)) {
			cout << -1 << '\n';
			continue;
		}
		for (i = n; i < maxT; i++)
			if (dinic(i)) break;
		cout << i << '\n';
	}
}
