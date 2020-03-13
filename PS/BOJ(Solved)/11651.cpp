/*
좌표 정렬하기 2
https://www.acmicpc.net/problem/11651
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int n, a, b;

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(b, a);
	}
	sort(v.begin(), v.end(), less<pair<int, int> >());
	for (i = 0; i < n; i++) 
		cout << v[i].second << ' ' << v[i].first << '\n';
}
