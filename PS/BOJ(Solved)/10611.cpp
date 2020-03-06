/*
PSENICA
https://www.acmicpc.net/problem/10611
Algorithm : 
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

int n, x, cnt[100007], s, e;
vector<int> v;
bool turn = true;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> x;
		if (!cnt[x]++)
			v.push_back(x);
	}
	sort(v.begin(), v.end());
	s = 0, e = v.size()-1;
	while (e - s + 1 >= 3) {
		int a = v[s], b = v[e];
		if (cnt[a] > cnt[b]) {
			cnt[v[--e]] += cnt[b];
			cnt[v[s+1]] += cnt[b];
			cnt[v[s]] -= cnt[b];
			cnt[b] = 0;
			turn = true;
		}
		else if (cnt[a] < cnt[b]) {
			cnt[v[++s]] += cnt[a];
			cnt[v[e - 1]] += cnt[a];
			cnt[v[e]] -= cnt[a];
			cnt[a] = 0;
			turn = false;
		}
		else {
			if (e - s + 1 == 3) {
				turn = !turn;
				turn ? s++ : e--;
				break;
			}
			cnt[v[++s]] += cnt[a];
			cnt[v[--e]] += cnt[b];
		}
	}
	cout << (turn ? "Slavko" : "Mirko") << '\n' << v[s] << ' ' << v[e];
}
