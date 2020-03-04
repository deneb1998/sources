/*
풍선
https://www.acmicpc.net/problem/4716
Algorithm : Grid
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, x, y, a, b, c, ans, cnt;
struct node { int da, db, remain; };
vector<node> v;

bool cmp(node a, node b) {
	return abs(a.da - a.db) > abs(b.da - b.db);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		ans = cnt = 0;
		v.clear();
		cin >> n >> x >> y;
		if (!n && !x && !y) return 0;
		int i, j;
		for (i = 0; i < n; i++) {
			cin >> a >> b >> c;
			v.push_back(node{ b,c,a });
		}
		sort(v.begin(), v.end(), cmp);
		for (i = 0; i < n; i++) {
			if (v[i].da < v[i].db) {
				if (x >= v[i].remain) {
					ans += v[i].remain * v[i].da;
					x -= v[i].remain;
					v[i].remain = 0;
				}
				else {
					ans += x * v[i].da;
					v[i].remain -= x;
					x = 0;
					break;
				}
			}
			else if (v[i].da > v[i].db) {
				if (y >= v[i].remain) {
					ans += v[i].remain * v[i].db;
					y -= v[i].remain;
					v[i].remain = 0;
				}
				else {
					ans += y * v[i].db;
					v[i].remain -= y;
					y = 0;
					break;
				}
			}
			else {
				ans += v[i].remain * v[i].da;
			}
		}
		for (i = 0; i < n; i++) {
			if (v[i].remain == 0)
				continue;
			if (!x)
				ans += v[i].remain * v[i].db;
			else if (!y)
				ans += v[i].remain * v[i].da;
		}
		cout << ans << '\n';
	}
}
