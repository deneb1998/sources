/*
이항 계수 2
https://www.acmicpc.net/problem/11051
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

unsigned long long c[1001][1001];
int a, b;

int calc(int n, int k) {
	if (c[n][k]) return c[n][k];
	if (n - k < k) return c[n][k] = calc(n, n - k);
	if (k == 1) return c[n][k] = n;
	if (k == 0) return c[n][k] = 1;
	return c[n][k] = (calc(n - 1, k - 1) + calc(n - 1, k)) % 10007;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int i, j;
	cout << calc(a, b);
}
