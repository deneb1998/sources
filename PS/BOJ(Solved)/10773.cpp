/*
제로
https://www.acmicpc.net/problem/10773
*/
#include <bits/stdc++.h>
using namespace std;

int n, a, s;
stack<int> st;

int main() {
	cin >> n;
	while (n--) {
		cin >> a;
		if (!a && !st.empty())
			st.pop();
		else st.push(a);
	}
	while (!st.empty()) {
		s += st.top();
		st.pop();
	}
	cout << s;
}
