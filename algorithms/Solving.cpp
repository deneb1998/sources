/*
텀 프로젝트
https://www.acmicpc.net/problem/9466
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int T, n, arr[100010], ans, hasTeam[100010];

void cycle(int x) {
	if (hasTeam[x] != 0)
		return;
	int now = x;
	bool visited[100010];
	vector<int> v;
	memset(visited, false, sizeof(visited));
	while (1) {
		if (hasTeam[now] != 0) {
			for (int i : v)
				hasTeam[i] = -1;
			return;
		}
		visited[now] = true;
		v.push_back(now);
		if (visited[arr[now]]) {
			while (hasTeam[now] == 0) {
				hasTeam[now] = 1;
				now = arr[now];
				ans++;
			}
			for (int i : v) {
				if (hasTeam[i] == 0)
					hasTeam[i] = -1;
			}
			break;
		}
		now = arr[now];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(hasTeam, 0, sizeof(hasTeam));
		ans = 0;
		cin >> n;
		int i, j;
		for (i = 1; i <= n; i++)
			cin >> arr[i];
		for (i = 1; i <= n; i++) {
			cycle(i);
		}
		cout << n - ans << '\n';
	}
}
