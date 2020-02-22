/*
웜홀
https://boj.kr/1865
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF ((1<<31) - 1)
using namespace std;

int tc, n, m, w, s, e, t, dist[505];
struct node {
	int a, b, val;
};
vector<node> edge;

bool b_f() {
	bool isChanged = false;
	for (auto i : edge) {
		if (dist[i.a] == INF)
			continue;
		if (dist[i.a] + i.val < dist[i.b]) {
			isChanged = true;
			dist[i.b] = dist[i.a] + i.val;
		}
	}
	return isChanged;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		fill(dist, dist + 504, INF);
		edge.clear();
		dist[1] = 0;
		cin >> n >> m >> w;
		while (m--) {
			cin >> s >> e >> t;
			edge.push_back(node{ s, e, t });
			edge.push_back(node{ e, s, t });
		}
		while (w--) {
			cin >> s >> e >> t;
			edge.push_back(node{ s, e, -t });
		}
		m = n;
		while (m--)
			b_f();
		if (b_f())
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
}
