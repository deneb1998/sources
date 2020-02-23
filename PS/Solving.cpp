/*
웜홀
https://www.acmicpc.net/problem/1865
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define INF ((1<<31) - 1)
using namespace std;

int tc, n, m, w, a, b, c, cnt[510], dist[510];
struct node {
	int to, v;
};
vector<node> edge[6010];

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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 6010; i++)
			edge[i].clear();
		cin >> n >> m >> w;
		while (m--) {
			cin >> a >> b >> c;
			edge[a].push_back(node{ b, c });
			edge[b].push_back(node{ a, c });
		}
		while (w--) {
			cin >> a >> b >> c;
			edge[a].push_back(node{ b, c });
		}
		cout << (spfa() ? "NO" : "YES");
	}
}
