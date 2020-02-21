/*
타임머신
https://boj.kr/11657
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF (1<<30)
using namespace std;

int n, m, a, b, c, dist[505];
struct node {
	int x, y, val;
};
vector<node> v;

bool bellman_ford() {
	bool isChanged = false;
	for (auto i : v) {
		if (dist[i.x] == INF)
			continue;
		if (dist[i.x] + i.val < dist[i.y]) {
			dist[i.y] = dist[i.x] + i.val;
			isChanged = true;
		}
	}
	return isChanged;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	fill(dist, dist + 503, INF);
	dist[1] = 0;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v.push_back(node{ a,b,c });
	}
	m = n;
	while (m--)
		bellman_ford();
	if (bellman_ford())
		cout << -1;
	else {
		for (int i = 2; i <= n; i++)
			cout << (dist[i] < INF ? dist[i] : -1) << '\n';
	}

}
