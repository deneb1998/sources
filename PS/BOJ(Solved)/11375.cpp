/*
열혈강호
https://www.acmicpc.net/problem/11375
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

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
		if (dfs(i))
			ans++;
	}
	cout << ans;
}
