#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int n, x, minn, maxx;
long long ans = 0;
map<int, int> m;

int main() {
	cin >> n;
	cin >> x;
	m[x] = 0;
	cout << "0\n";
	while (--n) {
		scanf("%d", &x);
		map<int, int>::iterator itr = m.end();
		itr--;
		if (itr->first < x) 
			m[x] = itr->second + 1;
		else {
			itr = m.lower_bound(x);
			if (itr == m.begin()) 
				m[x] = itr->second + 1;
			else {
				m[x] = itr->second;
				itr--; itr--;
				if (itr->second > m[x]) m[x] = itr->second;
				m[x]++;
			}
		}
		ans += m[x];
		printf("%lld\n", ans);
	}
}
