/*
경로 찾기
https://www.acmicpc.net/problem/11403
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, edge[200][200];
vector<int> ans[200];
bool done[200];
stack<int> st;

void dfs(int start) {
	int i, j;
	bool check[200] = { false, };
	st.push(start);
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		for (i = 0; i < n; i++) {
			if (edge[now][i] && !check[i]) {
				st.push(i);
				ans[start].push_back(i);
				check[i] = true;
			}
		}
	}
	
	sort(ans[start].begin(), ans[start].end());
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	int i, j, cnt, size;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> edge[i][j];

	dfs(0);

	for (i = 0; i < n; i++) {
		dfs(i);
		for (j = cnt = 0, size = (int)ans[i].size(); j < n; j++) {
			if (cnt < size && ans[i][cnt] == j) {
				cout << "1 ";
				cnt++;
			}
			else
				cout << "0 ";
		}
		cout << '\n';
	}

}
