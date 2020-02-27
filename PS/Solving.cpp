https://www.acmicpc.net/problem/1671

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
#define INF ((1<<31) - 1)
#define maxN 60
using namespace std;

int n, a, b, c, matched[52], ans, it[52], cnt[52];
struct node {
	int x, y, z;
};
vector<node> shark;

bool cmp(node a, node b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.z < b.z;
}

int dfs(int now, int change_cnt) {
	cnt[now] += change_cnt;
	for (; it[now] < now; it[now]++) {
		if(shark[now].y < shark[it[now]].y || shark[now].z < shark[it[now]].z || (matched[it[now]] != -1 && !dfs(matched[it[now]], -1)))
			continue;
		matched[it[now]] = now;
		if (cnt[now] < 2) 
			cnt[now]++;
		if (cnt[now] == 2) {
			it[now]++;
			break;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;
		shark.push_back(node{ a,b,c });
	}
	sort(shark.begin(), shark.end(), cmp);
	memset(matched, -1, sizeof(matched));
	for (i = 0; i < n; i++)
		dfs(i, 0);
	for (i = 0; i < n; i++)
		if (matched[i] == -1) 
			ans++;
	cout << ans;
}
