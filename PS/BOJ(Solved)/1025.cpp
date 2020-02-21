/*
제곱수 찾기
https://www.acmicpc.net/problem/1025
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, m, arr[10][10];

int main() {
	int i, j, x, y, sx, sy, temp, root, ans = -1;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; scanf("%1d", &arr[i][j++]));
	for (i = 1 - n; i <= n - 1; i++) {
		for (j = 1 - m; j <= m - 1; j++) {
			if (i == 0 && j == 0) continue; //공차가 (0,0)일 경우 무한루프 방지
			for (x = 1; x <= n; x++) {
				for (y = 1; y <= m; y++) {
					sx = x; sy = y; temp = arr[x][y];
					while (sx + i > 0 && sx + i <= n && sy + j > 0 && sy + j <= m) {
						sx += i; sy += j;
						temp *= 10;
						temp += arr[sx][sy];
						root = (int)(sqrt((double)temp) + 0.5);
						if (temp > ans&& root* root == temp)
							ans = temp;
					}
				}
			}
		}
	}
	//탐색 결과가 9 미만이면 한자리수만 1,4,9인지 탐색
	if (ans < 9) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (arr[i][j] == 9) ans = 9;
				else if (arr[i][j] == 4 && ans < 4) ans = 4;
				else if (arr[i][j] == 1 && ans < 1) ans = 1;
				else if (arr[i][j] == 0 && ans < 0) ans = 0;
			}
		}
	}
	cout << ans;

}
