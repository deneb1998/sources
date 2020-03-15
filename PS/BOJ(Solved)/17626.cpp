/*
Four Squares
https://www.acmicpc.net/problem/17626
*/
#include <bits/stdc++.h>
#define INF ((1<<31) - 1)
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

//224^2 = 50176
int n, a[224];

bool func(int now, int m, int cnt, int sum) {
	if (cnt == m)
		return sum == n;
	if (now >= 224)
		return false;
	bool x, y;
	x = func(now + 1, m, cnt, sum);
	y = func(now, m, cnt + 1, sum + a[now]);
	return (x || y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i;
	for (i = 1; i < 224; i++)
		a[i] = i * i;
	for (i = 1; i < 4; i++) {
		if (func(1, i, 0, 0))
			break;
	}
	cout << i;
}
