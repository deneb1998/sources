/*
연결 요소의 개수
https://www.acmicpc.net/problem/11724
BFS
*/

#include <bits/stdc++.h>
#define PI 3.141592
#define INF ((1<<31)-1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

/*              PS start              */

int n, m, ans;
vector<int> edge[1010];
bool chk[1010];

void bfs(int s) {
	ans++;
	queue<int> q;
	q.push(s);
	chk[s] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto to : edge[now]) {
			if (!chk[to]) {
				chk[to] = true;
				q.push(to);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int a, b, i;
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		if (!chk[i])
			bfs(i);
	}
	cout << ans;
}
