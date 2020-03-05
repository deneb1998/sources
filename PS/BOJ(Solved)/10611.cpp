/*
PŠENICA
https://www.acmicpc.net/problem/10611
Algorithm : 정렬, 
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

int n, x, cnt;
vector<int> v;
bool turn = true, check[100007];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x;
		v.push_back(x);
		if (!check[x]) {
			check[x] = true;
			cnt++;
		}
	}
	auto it = v.begin();
	sort(v.begin(), v.end());
	while (cnt >= 3) {
		if (turn) {
			for (it = v.begin(); (*it) == v.front(); it++);
			int next = *it;
			it--;
			if (it == v.begin()) cnt--;
			*it = next;
		}
		else {
			for (it = --v.end(); (*it) == v.back(); it--);
			int next = *it;
			it++; it++;
			if (it == v.end()) cnt--;
			it--;
			*it = next;
		}
		turn = !turn;
	}
	cout << (turn ? "Slavko" : "Mirko") << '\n' << v.front() << ' ' << v.back();
}
