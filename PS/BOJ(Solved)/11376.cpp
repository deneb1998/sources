/*
열혈강호 2
https://www.acmicpc.net/problem/11376
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int n, m, a, b, parent[1010], child[1010], ans;
vector<int> edge[1010];
bool visited[1010];

bool dfs(int now) {
	if (visited[now]) 
		return false;
	visited[now] = true;
	for (auto to : edge[now]) {
		if (parent[to] == now)
			continue;
		if (!parent[to] || dfs(parent[to])) {
			parent[to] = now;
			if(++child[now] >= 2)
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			edge[i].push_back(b);
		}
		sort(edge[i].begin(), edge[i].end());
	}
	for (i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}
	for (i = 1; i <= m; i++)
		if (parent[i]) ans++;
	cout << ans;
}
