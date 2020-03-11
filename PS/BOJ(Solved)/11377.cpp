/*
열혈강호 3
https://www.acmicpc.net/problem/11377
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
#define k 2048
#define e (n+m+1)
#define maxN 2060
#define INF ((1<<31) - 1)
using namespace std;

int n, m, c, cap[maxN][maxN], flow[maxN][maxN], a, b, ans, level[maxN];
vector<int> edge[maxN];

bool leveling() {
	queue<int> q;
	memset(level, 0, sizeof(level));
	level[0] = 1;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == e) return true;
		for (auto to : edge[now]) {
			if (!level[to] && cap[now][to] > flow[now][to]) {
				level[to] = level[now] + 1;
				q.push(to);
			}
		}
	}
	return false;
}

int dfs(int now, int canFlow) {
	if (now == e) {
		ans += canFlow;
		return canFlow;
	}
	for (auto to : edge[now]) {
		if (level[to] == level[now] + 1 && cap[now][to] > flow[now][to]) {
			int res = dfs(to, min(canFlow, cap[now][to] - flow[now][to]));
			if (res > 0) {
				flow[now][to] += res;
				flow[to][now] -= res;
				return res;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> c;
	int i;
	edge[0].push_back(k);
	edge[k].push_back(0);
	cap[0][k] = c;
	for (i = 1; i <= n; i++) {
		cin >> a;
		edge[0].push_back(i);
		edge[i].push_back(0);
		cap[0][i] = 1;
		edge[k].push_back(i);
		edge[i].push_back(k);
		cap[k][i] = 1;
		while (a--) {
			cin >> b;
			edge[i].push_back(n + b);
			edge[n + b].push_back(i);
			cap[i][n + b] = 1;
		}
	}
	for (i = n + 1; i <= n + m; i++) {
		edge[i].push_back(e);
		edge[e].push_back(i);
		cap[i][e] = 1;
	}
	while (leveling()) {
		while (1) {
			if (!dfs(0, INF))
				break;
		}
	}
	cout << ans;
}
