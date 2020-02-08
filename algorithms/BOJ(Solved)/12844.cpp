/*
XOR
https://www.acmicpc.net/problem/12844
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, m, t, a, b, c, sn, tree[4004000], lazy[4004000];

void propagate(int s, int e, int x) {
	if (lazy[x]) {
		tree[x] ^= ((e - s + 1) % 2) * lazy[x];
		if (s != e) {
			lazy[x * 2] ^= lazy[x];
			lazy[x * 2 + 1] ^= lazy[x];
		}
		lazy[x] = 0;
	}
}

void update(int s, int e, int x) {
	if (s > e || x >= sn * 2) return;
	propagate(s, e, x);
	if (s > b || e < a) return;
	if (s >= a && e <= b) {
		lazy[x] = c;
		propagate(s, e, x);
		return;
	}
	update(s, (s + e) / 2, x * 2);
	update((s + e) / 2 + 1, e, x * 2 + 1);
	tree[x] = tree[x * 2] ^ tree[x * 2 + 1];
}

int query(int s, int e, int x) {
	if (s > e || x >= sn * 2) return 0;
	propagate(s, e, x);
	if (s > b || e < a) return 0;
	if (s >= a && e <= b) return tree[x];
	return query(s, (s + e) / 2, x * 2) ^ query((s + e) / 2 + 1, e, x * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> n;
	for (sn = 1; sn < n; sn *= 2);
	for (i = sn; i < sn + n; i++) {
		cin >> tree[i];
		for (j = i / 2; j > 0; j /= 2)
			tree[j] ^= tree[i];
	}
	cin >> m;
	while (m--) {
		cin >> t >> a >> b;
		a++, b++;
		if (a > b) swap(a, b);
		if (t == 1) {
			cin >> c;
			update(1, sn, 1);
		}
		else 
			cout << query(1, sn, 1) << '\n';
	}
}
