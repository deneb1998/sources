/*
구슬 탈출 2
https://www.acmicpc.net/problem/13460
*/


#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define nextB arr[locB.first][locB.second]
#define nextR arr[locR.first][locR.second]
#define make_node(a, b, c) newNode.depth = a; newNode.ex = b; memcpy(newNode.arr, c, sizeof(c));
typedef long long ll;
using namespace std;

int dx[4] = { -1,1,0,0 },
dy[4] = { 0,0,-1,1 };
int n, m;
char mymap[12][12];
pair<int, int> locB, locR;

int moveMap(int dir, char* tmp) {
	char save[12][12];
	char arr[12][12];
	bool isRGoal = false;
	memcpy(arr, tmp, sizeof(arr));
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 'R')
				locR = make_pair(i, j);
			if (arr[i][j] == 'B')
				locB = make_pair(i, j);
		}
	while (1) {
		memcpy(save, arr, sizeof(arr));
		while (1) {
			pair<int, int> temp = locB;
			locB.first += dx[dir];
			locB.second += dy[dir];
			if (nextB == '#' || nextB == 'R') {
				locB.first -= dx[dir];
				locB.second -= dy[dir];
				break;
			}
			if (nextB == 'O') {
				memcpy(tmp, arr, sizeof(arr));
				return -1;
			}
			nextB = 'B';
			arr[temp.first][temp.second] = '.';
		}

		while (!isRGoal) {
			pair<int, int> temp = locR;
			locR.first += dx[dir];
			locR.second += dy[dir];
			if (nextR == '#' || nextR == 'B') {
				locR.first -= dx[dir];
				locR.second -= dy[dir];
				break;
			}
			if (nextR == 'O') {
				isRGoal = true;
				locR.first -= dx[dir];
				locR.second -= dy[dir];
				nextR = '.';
				break;
			}
			nextR = 'R';
			arr[temp.first][temp.second] = '.';
		}
		bool isChange = false;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (save[i][j] != arr[i][j]) {
					isChange = true;
					break;
				}
			}
			if (isChange)
				break;
		}
		if (!isChange)
			break;
	}
	memcpy(tmp, arr, sizeof(arr));
	if (isRGoal)
		return 1;
	return 0;
}

struct node {
	int depth, ex;
	char arr[12][12];
	vector<int> list;
};

int bfs() {
	queue<node> qu;
	node newNode;
	make_node(1, -1, mymap);
	qu.push(newNode);
	int i;

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();
		for (i = 0; i < 4; i++) {
			if (now.ex == i) continue;
			char save[12][12];
			memcpy(save, now.arr, sizeof(save));
			int is = moveMap(i, &(now.arr[0][0]));
			if (is == 1) {
				cout << now.depth << '\n';
				exit(0);
			}
			if (!is) {
				make_node(now.depth + 1, i, now.arr);
				newNode.list = now.list;
				newNode.list.push_back(i);
				qu.push(newNode);
				newNode.list.erase(--newNode.list.end());
			}
			memcpy(now.arr, save, sizeof(save));
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> mymap[i][j];
			if (mymap[i][j] == 'R')
				locR = make_pair(i, j);
			if (mymap[i][j] == 'B')
				locB = make_pair(i, j);
		}
	cout << bfs();
}
