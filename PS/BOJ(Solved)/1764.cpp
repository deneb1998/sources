/*
듣보잡
https://www.acmicpc.net/problem/1764
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

int n, m;
string s;
vector<string> a, ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	while (n--) {
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	while (m--) {
		cin >> s;
		auto it = lower_bound(a.begin(), a.end(), s);
		if ((*it) == s)
			ans.push_back(s);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i = ans.begin(); i != ans.end(); i++)
		cout << *i << '\n';
}
