/*
회의실 배정
https://www.acmicpc.net/problem/1931
pair<int, int> 를 second 기준으로 오름차순 정렬 
*/

#include <bits/stdc++.h>
#define PI 3.141592
#define INF ((1<<31)-1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

/*              PS start              */

int n, mt, ans;
vector<pair<int, int> > v;

bool cmp (pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i, j;
	while (n--) {
		cin >> i >> j;
		v.emplace_back(i, j);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it = v.begin(); it != v.end(); it++) {
		if (it->first >= mt) {
			mt = it->second;
			ans++;
		}
	}
	cout << ans;
}
