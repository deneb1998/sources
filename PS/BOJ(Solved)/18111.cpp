/*
마인크래프트
https://www.acmicpc.net/problem/18111
*/
#include <bits/stdc++.h>
#define INF ((1<<31) - 1)
using namespace std;

int n, m, b, myMap[510][510], ans = INF, ans_i;

int calc(int x, int have) {
	int i, j, ret = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (myMap[i][j] > x) {
				have += myMap[i][j] - x;
				ret += (myMap[i][j] - x) * 2;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (myMap[i][j] < x) {
				if (have < x - myMap[i][j])
					return INF;
				have -= x - myMap[i][j];
				ret += x - myMap[i][j];
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> b;
	int i, j, s, e;
	s = INF, e = -1;
	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++) { 
			cin >> myMap[i][j]; 
			s = min(s, myMap[i][j]);
			e = max(e, myMap[i][j]);
		}
	for (i = s; i <= e; i++) {
		int ret = calc(i, b);
		if (ret <= ans) {
			ans = ret;
			ans_i = i;
		}
	}
	cout << ans << ' ' << ans_i;
}
