#include <cstdio>

char loc[51][51];
int n, m, ans=65, sum;

int main() {
	int i, j, k, l;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; scanf("%s", loc[i++]));
	for (i = 0; i <= n - 8; i++)
		for (j = 0; j <= m - 8; j++) {
			sum = 0;
			for (k = i; k < i + 8; k++)
				for (l = j; l < j + 8; l++) {
					if (((k + l) % 2) && loc[k][l] != 'B') sum++;
					if (!((k + l) % 2) && loc[k][l] != 'W') sum++;
				}
			if (sum > 32) sum = 64 - sum;
			if (ans > sum) ans = sum;
		}
	printf("%d", ans);
}
