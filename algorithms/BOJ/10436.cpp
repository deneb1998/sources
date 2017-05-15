#include <cstdio>
#define ll long long

ll n, p, q, a[100], a2[100][2];
int c, c2;
char s[100];

void func() {
	ll tmp;
	if (q == 1) {
		q = p + 1;
		p = 1;
		return;
	}
	if (p < q) {
		tmp = p;
		p = q;
		q -= tmp;
		return;
	}
	tmp = p / q;
	p %= q;
	func();
	for (int i = 0; i < tmp; i++)
		q += p;
}

int main() {
	int t, st, i, j;
	scanf("%d", &t);
	st = t;
	while (t--) {
		c = c2 = p = q = 0;
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
		func();
		printf("%lld ", n);
		printf("%lld/", p);
		printf("%lld\n", q);
	}
}
