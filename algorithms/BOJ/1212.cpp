#include <cstdio>
#include <cstring>
using namespace std;

char n[333335];
int a[3];

int main() {
	scanf("%s", n);
	int s = strlen(n), i, j;
	if (s == 1 && n[0] == '0') {
		printf("0");
		return 0;
	}
	bool isFirst = true;
	for (i = 0; i < s; i++) {
		int x=n[i]-'0';
		for (j = 0; j < 3; j++) {
			a[j] = x % 2;
			x /= 2;
		}
		for (j = 2; j >= 0; j--) {
			if (isFirst && a[j]) {
				printf("%d", a[j]);
				isFirst = false;
			}
			else if (!isFirst)
				printf("%d", a[j]);
		}
	}
}
