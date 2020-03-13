/*
영화감독 숌
https://www.acmicpc.net/problem/1436
Algorithm : Brute Force
*/
#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool func(int x) {
	int tmp, cnt = 0;
	while (x) {
		tmp = x % 10;
		x /= 10;
		if (tmp == 6) {
			if (++cnt == 3)
				return true;
		}
		else
			cnt = 0;
	}
	return false;
}

int main() {
	int i, j;
	cin >> n;
	for (i = 665, j = 0; j < n; i++) {
		if (func(i)) {
			j++;
			ans = i;
		}
	}
	cout << ans;
}
