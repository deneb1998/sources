/*
열혈강호5
https://www.acmicpc.net/problem/11408
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
#define END (n + m + 1)
using namespace std;
typedef long long ll;

const int INF = ((1 << 31) - 1);
const int maxN = 805;
int n, m, a, b, c, cap[maxN][maxN], flow[maxN][maxN], cost[maxN][maxN], parent[maxN], ansCost, mf;
vector<int> edge[maxN];

bool spfa() {
	int dist[maxN];
	bool isInQ[maxN];
	queue<int> q;
	memset(parent, -1, sizeof(parent));
	memset(isInQ, 0, sizeof(isInQ));
	fill(dist, dist + maxN, INF);
	dist[0] = 0; 
	q.push(0); isInQ[0] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop(); isInQ[now] = false;
		for (auto to : edge[now]) {
			if (cap[now][to] <= flow[now][to] || dist[to] <= dist[now] + cost[now][to])
				continue;
			dist[to] = dist[now] + cost[now][to];
			parent[to] = now;
			if (!isInQ[to]) {
				q.push(to); isInQ[to] = true;
			}
		}
	}
	return parent[END] != -1;
}

void max_flow() {
	int child[maxN];
	memset(child, -1, sizeof(child));
	int now = END, minFlow = INF;
	while (1) {
		int p = parent[now];
		if (p == -1) break;
		child[p] = now;
		minFlow = min(minFlow, cap[p][now] - flow[p][now]);
		now = p;
	}
	mf += minFlow;
	now = 0;
	while (1) {
		int to = child[now];
		flow[now][to] += minFlow;
		flow[to][now] -= minFlow;
		ansCost += cost[now][to];
		now = to;
		if (now == END) 
			break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int i, j;
	for (i = 1; i <= n; i++) {
		edge[0].push_back(i);
		edge[i].push_back(0);
		cap[0][i] = 1;
	}
	for (i = 1; i <= m; i++) {
		edge[i + n].push_back(END);
		edge[END].push_back(i + n);
		cap[i + n][END] = 1;
	}
	for (i = 1; i <= n; i++) {
		cin >> a;
		while (a--) {
			cin >> b >> c;
			edge[i].push_back(n+b);
			edge[n + b].push_back(i);
			cap[i][n + b] = 1;
			cost[i][n + b] = c;
			cost[n + b][i] = -c;
		}
	}
	while (spfa()) {
		max_flow();
	}
	cout << mf << '\n' << ansCost;
}
