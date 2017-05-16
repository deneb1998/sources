#include <stdio.h>

int a, b, i;
char o[3];

int main() {
	while (1) {
		scanf("%d%s%d", &a, o, &b);
		int is = 0;
		if(o[0]=='>')
			is = o[1] ? a >= b : a > b;
		if(o[0]=='<')
			is = o[1] ? a <= b : a < b;
		if(o[0]=='=')
			is = a == b;
		if(o[0]=='E')
			exit(1);
		if(o[0]=='!')
			is = a != b;
		printf("Case %d: %s\n", ++i, is ? "true" : "false");
	}
}
