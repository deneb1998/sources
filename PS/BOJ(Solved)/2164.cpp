/*
카드2
https://www.acmicpc.net/problem/2164
Algorithm : 시뮬레이션, 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;
typedef long long ll;

int n;
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
		q.push(i);
	while (n-- != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
