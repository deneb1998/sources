bool spfa() {
	int s = startNumber;
	bool isInQ[510]; memset(isInQ, 0, sizeof(isInQ));
	fill(dist, dist + 509, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	isInQ[s] = true;
	cnt[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		isInQ[x] = false;
		for (auto i : edge[x]) {
			if (dist[x] + i.v >= dist[i.to])
				continue;
			dist[i.to] = dist[x] + i.v;
			if (!isInQ[i.to]) {
				if (++cnt[i.to] > n) //주의점 : if 밖에서 실행하면 안됨
					return false;
				q.push(i.to);
				isInQ[i.to] = true;
			}
		}
	}
	return true;
}

