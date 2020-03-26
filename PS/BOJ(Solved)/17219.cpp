/*
비밀번호 찾기
https://www.acmicpc.net/problem/17219
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

map<string, string> v;
int n, m;
string a, b;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	while (n--) {
		cin >> a >> b;
		v.emplace(a, b);
	}
	while (m--) {
		cin >> a;
		auto it = v.find(a);
		cout << it->second << '\n';
	}
}
