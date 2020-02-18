/*
알고스팟
https://www.acmicpc.net/problem/1261
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, m, myMap[105][105], d[105][105];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%1d", &myMap[i][j]);
	pq.emplace(0, 1001);
	memset(d, -1, sizeof(d));
	while (!pq.empty()) {
		int y = (pq.top().second / 1000), x = (pq.top().second % 1000), v = pq.top().first;
		pq.pop();
		if (d[y][x] != -1)
			continue;
		d[y][x] = v;
		if (y == n && x == m)
			break;
		for (i = 0; i < 4; i++) {
			if (x + dx[i] < 1 || x + dx[i] > m || y + dy[i] < 1 || y + dy[i] > n || d[y+dy[i]][x+dx[i]] != -1)
				continue;
			int next = (y + dy[i]) * 1000 + (x + dx[i]);
			pq.emplace(v + myMap[y + dy[i]][x + dx[i]], next);
		}
	}
	cout << d[n][m];
}
