/*
가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11055
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, a[1010], d[1010];

int dp(int ind) {
	if (d[ind])
		return d[ind];
	int max_, i;
	for (i = ind + 1, max_ = 0; i < n; i++) {
		if (a[i] > a[ind]) {
			int tmp = dp(i);
			if (tmp > max_)
				max_ = tmp;
		}
	}
	return d[ind] = max_ + a[ind];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int i, ans = -1, tmp;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++) {
		tmp = dp(i);
		if (ans < tmp)
			ans = tmp;
	}
	cout << ans;
}
