/*
2941 크로아티아 알파벳
https://www.acmicpc.net/problem/2941
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

string list[8] = { "c=", "c-", "dz", "d-", "lj", "nj", "s=", "z=" };
string s;
int len, ans = 0;

int func(int start) {
	if (start == len - 1)
		return 1;
	string two = s.substr(start, 2);
	for (int i = 0; i < 8; i++) {
		if (list[i].compare(two) == 0) {
			if (i == 2) {
				if (s[start + 2] == '=')
					return 3;
				else
					return 1;
			}
			else {
				return 2;
			}
		}
	}
	return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int now = 0;
	cin >> s;
	len = s.length();

	while (now < len) {
		now += func(now);
		ans++;
	}

	cout << ans;
}
