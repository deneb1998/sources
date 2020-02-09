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
#define p(a,b) make_pair((a), ((ll)b))
#define M (ll)(1e9+7)
typedef long long ll;
using namespace std;

ll n, t, ans;

class Node {
public:
	int val;
	ll dp;
	Node(int val, ll dp) :val(val), dp(dp) {}

	bool operator<(Node x) const {
		return this->val < x.val;
	}
};

vector<multiset<Node> > v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	ll x;
	int i, j;
	multiset<Node> ns;
	ns.insert(Node(-1234567890, 1));
	v.push_back(ns);
	t = n;
	while (t--) {
		cin >> x;
		if (v.back().begin()->val < x) {
			int tmp = v.size();
			ll sum = 0;
			for (auto it = v[tmp - 1].begin(); it != v[tmp - 1].end() && it->val < x; it++) {
				sum += it->dp;
				sum %= M;
			}
			multiset<Node> ns;
			ns.insert(Node(x, sum));
			v.push_back(ns);
		}
		else {
			vector<multiset<Node> >::iterator it, ex;
			multiset<Node> tmp;
			ll sum = 0;
			tmp.insert(Node(x, -1));
			it = lower_bound(v.begin(), v.end(), tmp);
			ex = it;
			it--;
			for (auto it2 = it->begin(); it2 != it->end() && it2->val < x; it2++) {
				sum += it2->dp;
				sum %= M;
			}
			(*ex).insert(Node(x, sum));
		}

	}

	int len = v.size();
	cout << len - 1 << ' ';
	
	for (auto it = v[len - 1].begin(); it != v[len - 1].end(); it++) {
		ans += it->dp;
		ans %= M;
	}
	cout << ans;
}
