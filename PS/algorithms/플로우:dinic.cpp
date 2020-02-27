int flow[maxN][maxN], cap[maxN][maxN], level[maxN], ans;
set<int> isConnected[maxN];

bool leveling() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(0);
	level[0] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto to : isConnected[now]) {
			if (level[to] != -1 || cap[now][to] <= flow[now][to])
				continue;
			level[to] = level[now] + 1;
			q.push(to);
			if (to == end)
				return true;
		}
	}
	return false;
}

int dfs(int now, int minFlow) {
	if (now == end) {
		ans += minFlow;
		return minFlow;
	}
	for (auto to : isConnected[now]) {
		if (level[to] != level[now] + 1 || cap[now][to] <= flow[now][to])
			continue;
		int res = dfs(to, min(minFlow, cap[now][to] - flow[now][to]));
		if (res > 0) {
			flow[now][to] += res;
			flow[to][now] -= res;
			return res;
		}
	}
	return 0;
}

int main() {
	while (leveling()) {
		while (1) {
			if (!dfs(0, INF))
				break;
		}
	}
	cout << ans;
}
