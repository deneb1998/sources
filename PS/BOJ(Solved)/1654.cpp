/*
랜선 자르기
https://www.acmicpc.net/problem/1654
*/
#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<int> v;

int bs(int s, int e, int ex) {
	int i, j, ret = 0;
	for (i = 0; i < k; i++)
		ret += v[i] / e;
	if (ret < n) {
		return bs(s, (s + e) / 2, e);
	}
	if (s >= e) return s;
	return bs(e, ex ,e);
}

int main() {
	cin >> k >> n;
	int i, j, s, e;
	for (i = 0; i < k; i++) {
		cin >> j;
		v.push_back(j);
		e = max(e, j);
	}
	cout << bs(0, e, -1);
}
