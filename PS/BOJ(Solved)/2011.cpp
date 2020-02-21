/*
암호코드
https://www.acmicpc.net/problem/2011
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
typedef long long ll;
using namespace std;

string s;
ll ans, mem[5010];
int len;

ll dp(int start) {
	int x = s[start] - '0';
	if (!x) {
		return mem[start] = 0;
	}
	if (mem[start])
		return mem[start];
	if (start == len || start == len - 1)
		return mem[start] = 1;
	else if (x == 1 || (x == 2 && start + 1 < len && s[start + 1] - '0' < 7)) {
		int a = dp(start + 1);
		int b = dp(start + 2);
		return mem[start] = (a + b) % 1000000;
	}
	else {
		return mem[start] = dp(start + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	len = s.size();
	cout << dp(0);
}
