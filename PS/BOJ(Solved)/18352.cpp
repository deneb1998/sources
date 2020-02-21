#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, m, k, x, a, b;
vector<int> edge[300010], ans;
bool check[300010];

void bfs() {
	queue<pair<int, int> > q;
	q.emplace(x, 0);
	while (!q.empty()) {
		int x = q.front().first, val = q.front().second;
		q.pop();
		if (check[x])
			continue;
		check[x] = true;
		if (val > k)
			return;
		if (val == k)
			ans.push_back(x);
		for (auto i : edge[x]) {
			if (check[i]) continue;
			q.emplace(i, val + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k >> x;
	int i;
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b);
	}
	bfs();
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << '\n';
	if (!ans.size())
		cout << -1;
}
