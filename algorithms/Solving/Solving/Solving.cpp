/*
이항 계수
https://www.acmicpc.net/problem/3651
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int c[21][21];
int a, b;

int calc(int n, int k) {
	if (c[n][k]) return c[n][k];
	if (n - k < k) return c[n][k] = calc(n, n - k);
	if (k == 1) return c[n][k] = n;
	if (k == 0) return c[n][k] = 1;
	return c[n][k] = calc(n - 1, k - 1) + calc(n - 1, k);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int i, j;
	for(i=1;i<21;i++)
		for (j = 1; j <= i; j++) {
			if (!c[i][j]) {
				c[i][j] = calc(i, j);
			}
		}
	while (1) {
		cin >> a;
		for (i = 1; i < 21; i++)
			for (j = 1; j <= i; j++) {
				if (c[i][j] == a) {
					cout << i << ' ' << j << '\n';
				}
			}
	}
}
