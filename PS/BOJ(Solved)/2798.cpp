/*
블랙잭
https://www.acmicpc.net/problem/2798
Algorithm : 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, m, v[102], ans = -1;

void solve(int i, int sum, int cnt) {
	if (i >= n) return;
	if (cnt == 3) {
		if (sum <= m)
			ans = max(ans, sum);
		return;
	}
	if (sum + v[i] > m)
		return;
	solve(i + 1, sum + v[i], cnt + 1);
	solve(i + 1, sum, cnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v + n);
	solve(0, 0, 0);
	cout << ans;
}
