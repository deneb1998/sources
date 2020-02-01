/*
가장 긴 증가하는 부분 수열 4
https://www.acmicpc.net/problem/14002
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int val, ex;
};

int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	int n, i, len = 0;
	node a[1010];
	vector<pair<int, int> > v;
	a[0].val = a[0].ex = -1;
	v.push_back(make_pair(-1, 0));
	cin >> n;
	for(i=1;i<n;i++) {
		cin >> a[i].val;
		if (a[i].val > v.back().first) {
			v.push_back(make_pair(a[i].val, i));
			a[i].ex = (--(--v.end()))->second;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a[i].val, cmp);
			it->first = a[i].val;
			it->second = i;
			a[i].ex = (--it)->second;
		}
	}
	cout << v.size() - 1;
}
