bool spfa() {
	bool isInQ[510]; memset(isInQ, 0, sizeof(isInQ));
	fill(dist, dist + 509, INF);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	isInQ[1] = true;
	cnt[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		isInQ[x] = false;
		for (auto i : edge[x]) {
			if (dist[x] + i.v >= dist[i.to])
				continue;
			dist[i.to] = dist[x] + i.v;
			if (!isInQ[i.to]) {
				if (++cnt[i.to] > n)
					return false;
				q.push(i.to);
				isInQ[i.to] = true;
			}
		}
	}
	return true;
}

