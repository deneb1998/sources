/*
15552 빠른 A+B
https://www.acmicpc.net/problem/15552
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int t, a, b;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
}
