/*
덩치
https://www.acmicpc.net/problem/7568
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int n, a, b;

int main() {
	cin >> n;
	int i, j;
	for(i=0;i<n;i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	for (i = 0; i < n; i++) {
		int res = 1;
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				res++;
		}
		cout << res << ' ';
	}
}
