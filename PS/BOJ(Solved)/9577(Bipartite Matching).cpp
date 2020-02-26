/*
토렌트 using 이분매칭
https://www.acmicpc.net/problem/9577
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define INF ((1<<31) - 1)
using namespace std;

int tc, n, m, t1, t2, a, q, can[102][102], maxT, connected[102];
vector<int> edge[102];
int it[102];

int dfs(int now) {
	int size = edge[now].size();
	for (; it[now] < size; it[now]++) {
		int to = edge[now][it[now]];
		if (connected[to] == -1 || dfs(connected[to])) {
			connected[to] = now;
			it[now]++;
			return 1;
		}
	}
	return 0;
}

bool matching(int limit) {
	memset(connected, -1, sizeof(connected));
	memset(it, 0, sizeof(it));
	int i, res = 0;
	for (i = 0; i < limit; i++) {
		if (dfs(i)) 
			res++;
	}
	return res == n;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	cin >> tc;
	while (tc--) {
		memset(can, 0, sizeof(can));
		for (i = 0; i < 102; i++)
			edge[i].clear();
		maxT = -1;
		cin >> n >> m;
		while (m--) {
			cin >> t1 >> t2 >> a;
			if (t2 > maxT) maxT = t2;
			while (a--) {
				cin >> q;
				for (i = t1; i < t2; i++)
					can[i][q] = 1;
			}
		}
		for (i = 0; i < maxT; i++) {
			for (j = 1; j <= n; j++)
				if (can[i][j]) edge[i].push_back(j);
		}
		for (i = n; i <= maxT; i++)
			if (matching(i))
				break;
		cout << (i <= maxT ? i : -1) << '\n';
	}
}
