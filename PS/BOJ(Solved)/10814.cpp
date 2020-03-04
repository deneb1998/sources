/*
나이순 정렬
https://www.acmicpc.net/problem/10814
Algorithm : 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, a;
string b;
struct node { int x, o; string s; };
vector<node> v;

bool cmp(node a, node b) {
	if (a.x != b.x) return a.x < b.x;
	return a.o < b.o;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a >> b;
		v.push_back(node{ a,i,b });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v)
		cout << i.x << ' ' << i.s << '\n';
}
