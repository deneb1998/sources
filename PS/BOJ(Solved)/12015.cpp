#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1000001];
vector<int> b;

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; scanf("%d", a + i++));
	b.push_back(a[0]);
	for (i = 1; i < n; i++) {
		if (b.back() < a[i])
			b.push_back(a[i]);
		else {
			auto t = lower_bound(b.begin(), b.end(), a[i]);
			*t = a[i];
		}
	}
	cout << b.size();
}
