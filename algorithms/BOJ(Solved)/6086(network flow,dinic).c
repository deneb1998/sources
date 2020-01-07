// Dinic Algorithm //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) ((a)>(b)?(b):(a))

int q[50000], front, rear, edge[701][701][2], n, a, b, c, len, ans, ex;
int check[701], level[701], conn[701][701];

void bfs() {
	int i, j, x, l;
	front = rear = 0;
	q[rear++] = 1;
	for (i = 1; i <= 70; check[i++] = 0);
	check[1] = 1;
	do {
		x = q[front++];
		l = level[x] + 1;
		for (i = 0; i < edge[x][0][0]; i++) {
			if (check[edge[x][i + 1][0]] || !edge[x][i+1][1]) continue;
			level[edge[x][i + 1][0]] = l;
			q[rear++] = edge[x][i + 1][0];
			check[edge[x][i + 1][0]] = 1;
		}
	} while (front != rear);
}

int dfs(int x, int minn, int ex) {
	if (x == 26) {
		len = minn;
		if (conn[x][ex])
			edge[x][conn[x][ex]][1] += len;
		else {
			edge[x][++edge[x][0][0]][0] = ex;
			edge[x][edge[x][0][0]][1] = len;
			conn[x][ex] = edge[x][0][0];
		}
		return len;
	}
	int i, j;
	for (i = 0; i < edge[x][0][0]; i++) {
		if (level[edge[x][i + 1][0]] != level[x] + 1 || !edge[x][i+1][1]) continue;
		if (dfs(edge[x][i + 1][0], min(minn, edge[x][i + 1][1]), x)) {
			edge[x][i + 1][1] -= len;
			if (conn[x][ex])
				edge[x][conn[x][ex]][1] += len;		
			else if (ex != -1) {
				edge[x][++edge[x][0][0]][0] = ex;
				edge[x][edge[x][0][0]][1] = len;
				conn[x][ex] = edge[x][0][0];
			}
			if (x == 1) ans += len;
			return len;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	scanf("%c", &a);
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%c %c %d", &a, &b, &c);
		a = a - 'A' + 1; b = b - 'A' + 1;
		edge[a][++edge[a][0][0]][0] = b;
		edge[a][edge[a][0][0]][1] = c;
		conn[a][b] = edge[a][0][0];
		scanf("%c", &a);
	}
	while (1) {
		bfs();
		if (!check[26]) break;
		while (dfs(1, 10000, -1));
	}
	printf("%d", ans);
}
