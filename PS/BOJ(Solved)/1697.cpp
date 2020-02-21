/*
숨바꼭질
https://www.acmicpc.net/problem/1697
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

int n, k;
bool ch[100010];
queue<pair<int, int> > q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	q.push(p(n, 0));
	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		if (x.first == k) {
			cout << x.second;
			break;
		}
		ch[x.first] = true;
		if (x.first > 0 && !ch[x.first - 1]) 
			q.push(p(x.first - 1, x.second + 1));
		if (x.first < 100000 && !ch[x.first + 1])
			q.push(p(x.first + 1, x.second + 1));
		if (x.first && x.first * 2 <= 100000)
			q.push(p(x.first * 2, x.second + 1));
	}
}
