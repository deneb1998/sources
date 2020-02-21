/*
단지번호붙이기
https://www.acmicpc.net/problem/2667
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
typedef long long ll;
using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int n, m[26][26], cnt =	2, sum[630];
bool ch[26][26];

void func(int x, int y) {
	if (ch[x][y] || x<0 || x>=n || y<0 || y>=n) return;
	ch[x][y] = true;
	if (!m[x][y]) return;
	m[x][y] = cnt;
	sum[cnt]++;
	for (int i = 0; i < 4; i++) 
		func(x + dx[i], y + dy[i]);
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%1d",&m[i][j]);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		if (m[i][j] == 1 && !ch[i][j]) {
			func(i, j);
			cnt++;
		}
	}
	sort(sum + 2, sum + cnt);
	cout << cnt - 2 << '\n';
	for (i = 2; i < cnt; i++)
		cout << sum[i] << '\n';
}
