#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1000001][3];
vector<int*> b;
vector<int> ans;

bool cmp(int *a, int *b) {
	return a[0] < b[0];
}

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
		a[i][2] = i;
	}
	b.push_back(a[0]); a[0][1] = -1;
	for (i = 1; i < n; i++) {
		if (b.back()[0] < a[i][0]) {
			a[i][1] = b.back()[2];
			b.push_back(a[i]);
		}
		else if (b.front()[0] >= a[i][0]) {
			a[i][1] = -1;
			b[0] = a[i];
		}
		else {
			auto t = lower_bound(b.begin(), b.end(), &a[i][0], cmp);
			*t = a[i];
			a[i][1] = (*(--t))[2];
		}
	}
	int s = b.size();
	cout << s << endl;
	for (i = b[s-1][2];;) {
		ans.push_back(a[i][0]);
		i = a[i][1];
		if (i == -1) break;
	}
	for (i = ans.size() - 1; i >= 0; i--)
		printf("%d ", ans[i]);
}
