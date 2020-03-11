int n, m, a, b, parent[1010], ans;
vector<int> edge[1010];
bool visited[1010];

bool dfs(int now) {
	if (visited[now]) 
		return false;
	visited[now] = true;
	for (auto to : edge[now]) {
		if (!parent[to] || dfs(parent[to])) {
			parent[to] = now;
			return true;
		}
	}
	return false;
}

int main() {
	for (i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}
	cout << ans;
}
