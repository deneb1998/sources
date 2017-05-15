#include <cstdio>

long long n, p, q, tmp;
char s[100];

int main() {
	int t, st, i, j;
	scanf("%d", &t);
	st = t;
	while (t--) {
		p = q = 0;
		scanf("%d %s", &n, s);
		for (i = 0;; i++) {
			if (s[i] == '/') break;
			p *= 10;
			p += s[i] - '0';
		}
		for (j = i + 1; s[j]; j++) {
			q *= 10;
			q += s[j] - '0';
		}
		if (q == 1) {
			q = p + 1;
			p = 1;
		}
		else {
			tmp = p / q;
			p %= q;
			q -= p;
			p += q;
			q += tmp*p;
		}
		printf("%d ", n);
		printf("%lld/%lld\n", p, q);
	}
}
