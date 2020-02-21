/*
그룹 단어 체커
https://www.acmicpc.net/problem/1316
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

int n, ans=0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int len = s.length(), i;
		bool isGroup = true, check[26] = { false, };
		for (i = 0; i < len; i++) {
			if (check[s[i] - 'a']) {
				isGroup = false;
				break;
			}
			if (!check[s[i] - 'a']) {
				if (i < len - 1 && s[i + 1] == s[i])
					continue;
				check[s[i] - 'a'] = true;
			}
		}
		if (isGroup)
			ans++;
	}
	cout << ans;
}
