/*
일곱 난쟁이
https://www.acmicpc.net/problem/2309
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
typedef long long ll;
using namespace std;

int v[9];

void func(int x, int a, int b, int cnt, int sum) {
	if (x == 9) {
		if (cnt == 2 && sum == 100) {
			int i;
			for (i = 0; i < 9; i++) {
				if (i == a || i == b) continue;
				cout << v[i] << '\n';
			}
			exit(0);
		}
		return;
	}
	if (cnt == 2)
		func(x + 1, a, b, cnt, sum + v[x]);
	else {
		func(x + 1, a, b, cnt, sum + v[x]);
		func(x + 1, cnt ? a : x, cnt ? x : b, cnt + 1, sum);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i;
	for (i = 0; i < 9; i++)
		cin >> v[i];
	sort(v, v + 9);
	func(0, -1, -1, 0, 0);
}
