/*
가장 긴 증가하는 부분 수열 5
https://www.acmicpc.net/problem/14003
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
pair<int, int> a[1000010];
vector<pair<int, int> > v;
vector<int> ans;

int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int i;
	v.push_back(make_pair(-1000000010, -1));

	for (i = 0; i < n; i++) {
		cin >> a[i].first;
		if (a[i].first > v.back().first) {
			a[i].second = v.back().second;
			v.push_back(make_pair(a[i].first, i));
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), make_pair(a[i].first, -1), cmp);
			it->first = a[i].first;
			it->second = i;
			a[i].second = (--it)->second;
		}
	}

	int len = v.size() - 1;
	cout << len << '\n';
	i = v.back().second;
	while (i != -1) {
		ans.push_back(a[i].first);
		i = a[i].second;
	}
	reverse(ans.begin(), ans.end());
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << ' ';
}
