/*
XOR
https://www.acmicpc.net/problem/12844
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, m, t, a, b, c, len = 0;
int seg_tree[1050000];

int seg_sum(int s, int e, int x) {
	if (s > e)
		return 0;
	if (s == e) {
		if (s >= a && e <= b)
			return seg_tree[x];
		return 0;
	}
	if (s >= a && e <= b)
		return seg_tree[x];
	if (s > b || e < a)
		return 0;
	return seg_sum(s, (s+e)/2, x * 2) ^ seg_sum((s+e) / 2 + 1, e, x * 2 + 1);
}

void seg_change(int s, int e, int x) {
	if (s > e)
		return;
	if (s == e) {
		if (s >= a && e <= b)
			seg_tree[x] ^= c;
		return;
	}
	if (s >= a && e <= b) {
		seg_tree[x] ^= ((e - s + 1) % 2 ? c : 0);
		seg_change(s, (s + e) / 2, x * 2);
		seg_change((s + e) / 2 + 1, e, x * 2 + 1);
		return;
	}
	if (s > b || e < a) 
		return;
	if (a >= s && b <= e) {
		seg_tree[x] ^= ((b - a + 1) % 2 ? c : 0);
		seg_change(s, (s + e) / 2, x * 2);
		seg_change((s + e) / 2 + 1, e, x * 2 + 1);
		return;
	}
	seg_tree[x] ^= ((e - a + 1) % 2 ? c : 0);
	seg_change(s, (s + e) / 2, x * 2);
	seg_change((s + e) / 2 + 1, e, x * 2 + 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j, k;
	cin >> n;
	for (i = 1; i < n; i *= 2);
	for (k = i; k < n + i; k++) {
		cin >> seg_tree[k];
		for (j = k / 2; j >= 1; j /= 2) {
			seg_tree[j] ^= seg_tree[k];
		}
	}
	cin >> m;
	while (m--) {
		cin >> t >> a >> b;
		a++, b++;
		if (a > b) swap(a, b);
		if (t == 2) {
			cout << seg_sum(1, i, 1) << '\n';
		}
		else {
			cin >> c;
			seg_change(1, i, 1);
		}
	}
}
