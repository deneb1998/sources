/*
음의 간선이 있을 경우 사용 불가
O(|E||log|V|)
*/

void dijkstra() {
	memset(dist, -1, sizeof(dist));
	priority_queue<pair<int, int> > pq;
	dist[s] = 0;
	pq.emplace(0, s);
	int cnt = 0;
	while (!pq.empty()) {
		int x = pq.top().second, val = pq.top().first;
		pq.pop();
		if (dist[x] != -1)
			continue;
		dist[x] = val;
		if (++cnt == n || x == e)
			break;
		for (auto i : edge[x]) {
			if (dist[i.second] != -1)
				continue;
			pq.emplace(i.first + val, i.second);
		}
	}
	cout << dist[e];
}
