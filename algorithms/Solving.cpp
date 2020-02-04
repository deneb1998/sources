/*
XOR
https://www.acmicpc.net/problem/12844
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, m, t, a, b, c;
int v[1300000], lazy[1300000];

void lazy_down(int s, int e, int ind) {
	if ((e - s + 1) % 2)
		v[ind] ^= lazy[ind];
	if (ind * 2 < 1300000)
		lazy[ind * 2] ^= lazy[ind];
	if (ind * 2 + 1 < 1300000)
		lazy[ind * 2 + 1] ^= lazy[ind];
	lazy[ind] = 0;
}

int calc(int s, int e, int x) {
	lazy_down(s, e, x);
	if (a <= s && b >= e) {
		if (s == e)
			return v[x];
		v[x] = 0;
		if (x * 2 < 1300000) 
			v[x] = v[x * 2] ^ (((s + e) / 2 - s + 1) % 2 ? lazy[x * 2] : 0);
		if (x * 2 + 1 < 1300000)
			v[x] ^= v[x * 2 + 1] ^ ((e - ((s + e) / 2 + 1) + 1) % 2 ? lazy[x * 2 + 1] : 0);
		return v[x];
	}
	if (e<a || s>b)
		return 0;
	return calc(s, (s + e) / 2, x * 2) ^ calc((s + e) / 2 + 1, e, x * 2 + 1);
}

void add(int s, int e, int x) {
	lazy_down(s, e, x);
	if (a <= s && b >= e) {
		lazy[x] = c;
		return;
	}
	if (e<a || s>b)
		return;
	add(s, (s + e) / 2, x * 2);
	add((s + e) / 2 + 1, e, x * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i, j, k;
	cin >> n;
	for (i = 1; i < n; i *= 2);
	for (j = i; j < i + n; j++) {
		cin >> v[j];
		for (k = j / 2; k > 0; k /= 2)
			v[k] ^= v[j];
	}
	cin >> m;
	while (m--) {
		cin >> t >> a >> b;
		a++, b++;
		if (a > b) swap(a, b);
		if (t == 1) {
			cin >> c;
			add(1, i, 1);
		}
		else {
			cout << calc(1, i, 1) << '\n';
		}
	}
}
