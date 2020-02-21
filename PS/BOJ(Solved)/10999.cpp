/*
구간 합 구하기 2
https://www.acmicpc.net/problem/10999
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
using namespace std;

int n, m, k, sn, a, b, c;
ll tree[2100000], lazy[2100000], d;

void propagate(int s, int e, int x) {
	if (lazy[x]) {
		tree[x] += (e - s + 1) * lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}

void update(int s, int e, int x) {
	if (s > e || x >= sn * 2) return;
	propagate(s, e, x);
	if (s > c || e < b) return;
	if (s >= b && e <= c) {
		lazy[x] = d;
		propagate(s, e, x);
		return;
	}
	update(s, (s + e) / 2, x * 2);
	update((s + e) / 2 + 1, e, x * 2 + 1);
	tree[x] = tree[x * 2] + tree[x * 2 + 1];
}

ll query(int s, int e, int x) {
	if (s > e || x >= sn * 2) return 0;
	propagate(s, e, x);
	if (s > c || e < b) return 0;
	if (s >= b && e <= c) return tree[x];
	return query(s, (s + e) / 2, x * 2) + query((s + e) / 2 + 1, e, x * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> n >> m >> k;
	for (sn = 1; sn < n; sn *= 2);
	for (i = sn; i < sn + n; i++) {
		cin >> tree[i];
		for (j = i / 2; j > 0; j /= 2)
			tree[j] += tree[i];
	}
	int t = m + k;
	while (t--) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update(1, sn, 1);
		}
		else 
			cout << query(1, sn, 1) << '\n';
	}
}
