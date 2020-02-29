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
	int minFlow = INF, i, child[maxN];
	for (i = END; i != 0; i = parent[i]) {
		int p = parent[i];
		child[p] = i;
		minFlow = min(minFlow, cap[p][i] - flow[p][i]);
	}
	for (i = END; i != 0; i = parent[i]) {
		int p = parent[i];
		flow[p][i] += minFlow;
		flow[i][p] -= minFlow;
	}
	ans += ;
}

int main() {
	while (spfa()) {
		max_flow();
	}
	cout << mf << '\n' << ansCost;
}
