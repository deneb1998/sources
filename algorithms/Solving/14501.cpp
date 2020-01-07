/*
14501 Επ»η
https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, t[15], p[15], ans = -1;

void func(int x, int sum) {
	if (x == n) {
		ans = max(ans, sum);
		return;
	}
	if (x > n)
		return;
	func(x + t[x], sum + p[x]);
	func(x + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);

	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		scanf("%d %d", t + i, p + i);
	func(0, 0);
	cout << ans;
}