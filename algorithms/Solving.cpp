/*
고스택
https://www.acmicpc.net/problem/3425
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
#define INF 2011111111
typedef long long ll;
using namespace std;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

stack<int> st;
vector<string> order;
string s;
vector<int> num;
int n;

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	st = stack<int>();
	order.clear();
	num.clear();
	while (1) {
		cin >> s;
		if (s[0] == 'Q') return 0;
		if (s[0] == 'E') break;
		if (s[0] == 'N') {
			int x;
			cin >> x;
			num.push_back(x);
		}
		order.push_back(s);
	}
	cin >> n;
	while (n--) {
		int x, len = order.size(), i, tmp, a, b;
		auto it = num.begin();
		cin >> x;
		st.push(x);
		for (i = 0; i < len; i++) {
			switch (order[i][0]) {
			case 'N' :
				st.push(*it++);
				break;
			case 'P' :
				st.pop();
				break;
			case 'I' :
				tmp = st.top();
				st.pop();
				st.push(-tmp);
				break;
			case 'D' :
				if (order[i][1] == 'U') {
					tmp = st.top();
					st.push(tmp);
				}
				else {
					a = st.top();
					st.pop();
					b = st.top();
					st.pop();
					tmp = abs(b) / abs(a);
					if ((a < 0 && b>0) || (a > 0 && b < 0))
						tmp = -tmp;
					st.push(tmp);
				}
				break;
			case 'S' :
				if (order[i][1] == 'W') {
					a = st.top();
					st.pop();
					b = st.top();
					st.pop();
					st.push(a);
					st.push(b);
				}
				else {
					a = st.top();
					st.pop();
					b = st.top();
					st.pop();
					st.push(b - a);
				}
				break;
			case 'A' :
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				st.push(b + a);
				break;
			case 'M' :
				if (order[i][1] == 'U') {
					a = st.top();
					st.pop();
					b = st.top();
					st.pop();
					st.push(b * a);
				}
				else {
					tmp = abs(b) % abs(a);
					if (b < 0)
						tmp = -tmp;
					st.push(tmp);
				}
				break;
			}
		}
	}
}
