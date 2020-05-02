/*
Z
https://www.acmicpc.net/problem/1074
분할정복
mymap으로 구현하지 않고 4구역의 번호가 어디부터 어디까지인지를 정하는 것이 핵심
*/

#include <bits/stdc++.h>
#define PI 3.141592
#define INF ((1<<31)-1)
#define pii pair<int, int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

/*              PS start              */

int N, r, c, n = 1;

void divide(int x1, int y1, int x2, int y2, int s, int m) {
	if (r > y2 || r < y1 || c > x2 || c < x1)
		return;
	if (x1 == x2 && y1 == y2 && r == y1 && c == x1) {
		cout << s - 1;
		exit(0);
	}
	divide(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, s, s + ((m - s + 1) / 4) - 1);
	divide((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2, s + ((m - s + 1) / 4), s + ((m - s + 1) / 4) * 2 - 1);
	divide(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2, s + ((m - s + 1) / 4) * 2, s + ((m - s + 1) / 4) * 3 - 1);
	divide((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2, s + ((m - s + 1) / 4) * 3, s + ((m - s + 1) / 4) * 4 - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> r >> c;
	for (int i = 0; i < N; i++)
		n *= 2;
	divide(0, 0, n - 1, n - 1, 1, n*n);
}
