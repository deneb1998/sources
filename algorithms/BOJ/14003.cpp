#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int x, ex;
};

int n, a[1000001];
vector<vector<node>> b;
vector<int> ans;

bool cmp(vector<node> a, vector<node> b) {
	return a.back().x < b.back().x;
}

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; scanf("%d", a + i++));
	b.push_back(vector<node>({ { a[0],-1 } }));
	for (i = 1; i < n; i++) {
		if (a[i] > b.back().back().x) {
			b.push_back(vector<node>({ { a[i], (int)(b.back().size()) - 1 } }));
		}
		else {
			auto t = lower_bound(b.begin(), b.end(), vector<node>({ { a[i],0 } }), cmp);
			if (t == b.begin()) t->push_back({ a[i],-1 });
			else {
				auto t2 = t--;
				t2->push_back({ a[i],(int)(t->size()) - 1 });
			}
		}
	}
	cout << b.size() << endl;
	int ex;
	vector<vector<node>>::iterator t = --b.end();
	ans.push_back(t->back().x);
	ex = t->back().ex;
	while (ex != -1) {
		t--;
		ans.push_back(t->at(ex).x);
		ex = t->at(ex).ex;
	}
	for (i = ans.size() - 1; i >= 0; printf("%d ", ans[i--]));
}
