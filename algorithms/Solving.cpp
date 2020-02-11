/*
최대유량 디닉 알고리즘 연습
https://jason9319.tistory.com/150
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int to;
	int cap;
	int flow;
};
int n, k, a, b, c, S, E, level[101];
vector<node> edge[101];

bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[S] = 0;
	q.push(S);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto i : edge[x]) {
			int to = i.to;
			int cap = i.cap;
			if (level[to] == -1 && cap > 0) {
				level[to] = level[x] + 1;
				q.push(to);
			}
		}
	}
	return level[E] != -1;
}

int main() {
	cin >> n, k;
	while (k--) {
		cin >> a >> b >> c;
		edge[a].push_back(node{ b,c,0 });
	}
	cin >> S >> E;


}
