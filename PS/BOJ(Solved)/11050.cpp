/*
이항 계수 1
https://www.acmicpc.net/problem/11050
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int c[11][11];
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
	cout << calc(a, b) << '\n';
}
