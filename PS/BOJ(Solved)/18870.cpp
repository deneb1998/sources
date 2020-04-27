/*
좌표 압축
https://www.acmicpc.net/problem/18870
index, value, ans 값을 갖는 node를 설정
value 순으로 정렬
value 값이 이전값과 다를 때마다 해당 노드의 ans를 이전 노드의 ans+1 로 설정
index 
*/

#include <bits/stdc++.h>
#define PI 3.141592
#define INF ((1<<31)-1)
#define pii pair<int, int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

/*              PS start              */

int n, x;
struct node {
	int ind, val, ans;
};
vector<node> v;

bool cmpByInd(node a, node b) {
	return a.ind < b.ind;
}

bool cmpByVal(node a, node b) {
	if (a.val != b.val) return a.val < b.val;
	return a.ind < b.ind;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> x;
		v.emplace_back(node{ i,x,-1 });
	}
	sort(v.begin(), v.end(), cmpByVal);

	v[0].ans = 0;
	for (i = 1, x = 0; i < n; i++) {
		if (v[i].val == v[i - 1].val)
			v[i].ans = v[i - 1].ans;
		else 
			v[i].ans = ++x;
	}
	sort(v.begin(), v.end(), cmpByInd);

	for (auto it = v.begin(); it != v.end(); it++)
		cout << it->ans << ' ';
}
