/*
비밀번호 만들기
https://www.acmicpc.net/problem/17218

func(x, y) 를 a[x~la]와 b[y~lb]에서의 비밀번호라고 놓자.
문제는 결국 func(0,0)을 구하는 것임
func(x, y) 를 구하는 방법은 다음과 같다.
먼저 a를 기본으로 놓고 b를 a에 맞추어나가자.
이러면 func(x, y)는 2가지로 나뉜다.
1) b[y]를 첫 문자로 포함하는 비밀번호
2) b[y]를 포함하지 않는 비밀번호
이 때 2번은 func(x, y+1) 로 쉽게 구할 수 있다.
1번은 b[y] + func(i+1, y+1) 인데 여기서 i는 a[x~la] 에서 처음으로 나오는 b[y]의 인덱스이다.
func(x, y)는 1번과 2번 중 길이가 더 긴 것을 택하면 된다.
la,lb <= 40 이므로 Memoization을 적용하여 DP로 풀면 O(NM)이다.
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

string a, b, dp[42][42];
int la, lb;

string func(int x, int y) {
	if (x >= la || y >= lb)
		return "";
	if (dp[x][y] != "")
		return dp[x][y];
	int i, lc, ld;
	string c, d = "";
	c = func(x, y + 1);
	for (i = x; i < la; i++)
		if (a[i] == b[y])
			break;
	if (i < la)
		d = b[y] + func(i + 1, y + 1);
	lc = c.size(); ld = d.size();
	return dp[x][y] = (lc > ld ? c : d);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b;
	la = a.size(), lb = b.size();
	cout << func(0, 0);
}
