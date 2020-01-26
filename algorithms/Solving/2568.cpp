/*
전깃줄 - 2
https://www.acmicpc.net/problem/2568
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n;
int min_num[100010][2], max_row;
pair<int, int> line[100010];
int link[100010];
bool check[100010] = { false, };

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int binary_search(int x, int l, int r) {
	int index = (int)((l + r) / 2);
	if (index == 1 && x < min_num[1][1])
		return 0;
	if (min_num[index][1] < x) {
		if (index == max_row || min_num[index + 1][1] > x)
			return index;
		return binary_search(x, index + 1, r);
	}
	return binary_search(x, l, index - 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j, a, b, index;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		line[i] = make_pair(a, b);
	}
	sort(line, line + n, compare);

	min_num[1][0] = 0;
	min_num[1][1] = line[0].second;
	link[0] = -1;
	max_row = 1;
	for (i = 1; i < n; i++) {
		if (min_num[1][1] > line[i].second) {
			min_num[1][0] = i;
			min_num[1][1] = line[i].second;
			link[i] = -1;
			continue;
		}
		index = binary_search(line[i].second, 1, max_row);
		if (index == max_row) {
			min_num[++max_row][1] = line[i].second;
		}
		else 
			min_num[index + 1][1] = line[i].second;
		link[i] = min_num[index][0];
		min_num[index + 1][0] = i;
	}
	cout << n - max_row << '\n';
	int x = min_num[max_row][0];
	while (x != -1) {
		check[x] = true;
		x = link[x];
	}
	for (i = 0; i < n; i++) {
		if (check[i]) continue;
		cout << line[i].first << '\n';
	}
}
