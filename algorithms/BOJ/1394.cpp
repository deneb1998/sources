#include <cstdio>
#include <cstring>

char key[101], pass[1000001];
int keymap[1000];
long long ans, tmp, x;

int main() {
	scanf("%s %s", key, pass);
	int i, j, lk = strlen(key), lp = strlen(pass);
	for (i = 0; i < lk; i++) {
		keymap[key[i]] = i + 1;
	}
	x = 1;
	for (i = lp - 1; i >= 0; i--) {
		ans = (ans + keymap[pass[i]] * x) % 900528;
		x = (x*lk) % 900528;
	}
	printf("%lld", ans);
}
