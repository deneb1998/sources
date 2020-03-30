/*
패션왕 신해빈
https://www.acmicpc.net/problem/9375
stl::map 을 이용해 각 키워드별로 수를 센다.
ex) 모자3 옷2 신발3
이 때 모자의 선택 가지수는 총 4개(3+안입는1), 옷은 3, 신발은 4이다.
그리고 답에서 모두 안입는 경우의 수는 제외하라고 했으므로 답은
3*2*3 - 1 이다.
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

int T, n, ans;
map<string, int> m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		m.clear();
		v.clear();
		cin >> n;
		string a, b;
		while (n--) {
			cin >> a >> b;
			auto it = m.find(b);
			if (it == m.end())
				m.emplace(b, 1);
			else
				m[b]++;
		}
		ans = 1;
		for (auto it = m.begin(); it != m.end(); it++)
			ans *= it->second + 1;
		cout << ans - 1 << '\n';
	}
}
