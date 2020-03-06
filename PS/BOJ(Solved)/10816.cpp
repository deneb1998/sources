/*
숫자 카드 2
https://www.acmicpc.net/problem/10816
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
#include <deque>
using namespace std;
typedef long long ll;

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	cin >> m;
	while (m--) {
		cin >> n;
		auto it = lower_bound(v.begin(), v.end(), n);
		if (*it != n)
			cout << "0 ";
		else {
			auto it2 = lower_bound(v.begin(), v.end(), n + 1);
			cout << it2 - it << ' ';
		}
	}
}
