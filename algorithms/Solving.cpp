/*
가장 긴 증가하는 부분 수열 6
https://www.acmicpc.net/problem/17411
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
#define M (1e9+7)
typedef long long ll;
using namespace std;

ll n, ans;
vector<multiset<int> > v;

bool cmp(multiset<int> a, multiset<int> b) {
	return (*(a.begin()) < *(b.begin()));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	ll x;
	multiset<int> ns;
	ns.insert(-1234567890);
	v.push_back(ns);
	while (n--) {
		cin >> x;
		if (*v.back().begin() < x) {
			multiset<int> ns;
			ns.insert(x);
			v.push_back(ns);
		}
		else {
			vector<multiset<int>>::iterator it = lower_bound(v.begin(), v.end(), x, cmp);
			(*it).insert(x);
		}
	}
	cout << v.size();
}
