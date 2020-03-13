/*
균형잡힌 세상
https://www.acmicpc.net/problem/4949
*/
#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;

int main() {
	while (1) {
		getline(cin, s);
		if (s == ".") break;
		int len = s.size(), i, yes = 1;
		for (i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					yes = 0;
					break;
				}
				st.pop();
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					yes = 0;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) yes = 0;
		cout << (yes ? "yes" : "no") << '\n';
		st = stack<int>();
	}
}
