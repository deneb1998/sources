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
	while (spfa()) {
		max_flow();
	}
	cout << mf << '\n' << ansCost;
}
