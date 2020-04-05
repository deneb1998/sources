/*
종이의 개수
https://www.acmicpc.net/problem/1780
분할정복
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

int n, mm[2222][2222], ans[3];

int isOne(int y1, int x1, int y2, int x2) {
	int i, j;
	for (i = y1; i <= y2; i++) for (j = x1; j <= x2; j++)
		if (mm[i][j] != mm[y1][x1]) return -2;
	return mm[y1][x1];
}

void func(int y1, int x1, int y2, int x2) {
	int i, j, tmp;
	tmp = isOne(y1, x1, y2, x2);
	if (tmp != -2) {
		ans[tmp + 1]++;
		return;
	}
	int a[4], b[4];
	a[0] = y1; b[0] = x1;
	a[1] = (y2 - y1 + 1) / 3 + y1; b[1] = (x2 - x1 + 1) / 3 + x1;
	a[2] = a[1] + (a[1] - a[0]); b[2] = b[1] + (b[1] - b[0]);
	a[3] = a[2] + a[1] - a[0]; b[3] = b[2] + b[1] - b[0];
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++)
		func(a[i], b[j], a[i + 1] - 1, b[j + 1] - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i, j;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) cin >> mm[i][j];
	func(1, 1, n, n);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
}
