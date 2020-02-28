// boj.kr/1671

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
#define INF ((1<<31) - 1)
#define maxN 105
#define END (n+n+1)
using namespace std;
typedef long long ll;

int n, a, b, c, cap[maxN][maxN], flow[maxN][maxN], level[maxN], ans;
struct node { int x, y, z; };
vector<node> shark;
vector<int> edge[maxN];

bool cmp(node a, node b) {
	if (a.x != b.x)	return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.z < b.z;
}

bool canEat(node a, node b) {
	return (a.x >= b.x && a.y >= b.y && a.z >= b.z);
}

bool leveling() {
	memset(level, -1, sizeof(level));
	level[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto to : edge[now]) {
			if (level[to] != -1 || cap[now][to] <= flow[now][to])
				continue;
			level[to] = level[now] + 1;
			q.push(to);
			if (to == END)
				return true;
		}
	}
	return false;
}

int dfs(int now, int minFlow) {
	if (now == END) {
		ans += minFlow;
		return minFlow;
	}
	int to;
	for (auto to : edge[now]) {
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
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		shark.push_back(node{ a,b,c });
		cap[0][i] = 2;
		edge[0].push_back(i);
		edge[i].push_back(0);
		cap[n + i][END] = 1;
		edge[n + i].push_back(END);
		edge[END].push_back(n + i);
	}
	sort(shark.begin(), shark.end(), cmp);
	for (i = 2; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (canEat(shark[i - 1], shark[j - 1])) {
				cap[i][n + j] = 1;
				edge[i].push_back(n + j);
				edge[n + j].push_back(i);
			}
		}
	}
	while (leveling()) {
		while (1) {
			if (!dfs(0, INF))
				break;
		}
	}
	cout << n - ans;
}
