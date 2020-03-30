/*
잃어버린 괄호
https://www.acmicpc.net/problem/1541
첫 -가 나온 이후의 모든 수는 뺄 수 있다.
그러므로 첫 -가 나오기 전의 수를 모두 더한 뒤 이후의 수를 뺀다.
*/

#include <bits/stdc++.h>
#define PI 3.141592
#define INF ((1<<31)-1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

/*              PS start              */

string s;
char x;
int ans, i, l;

int findNum() {
	int ret = 0;
	if (s[i] < '0') i++;
	for (; i < l; i++) {
		if (s[i] < '0') break;
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	l = s.size();
	do {
		ans += findNum();
	} while (i < l && s[i] == '+');
	while (i < l)
		ans -= findNum();
	cout << ans;
}
