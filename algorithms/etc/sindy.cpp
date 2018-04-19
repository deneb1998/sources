#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std;

bool ch[54];
int num, temp, total, i, sex, sum, minn=9999999, maxx=0;

int main() {
	srand((unsigned)time(NULL));
	while (sex<100000) {
		sex++;
		while (num != 51) {
			total++;
			temp = rand() % 54;
			if (!ch[temp]) {
				ch[temp] = true;
				num++;
			}
		}
		total += 60;
		total *= 10;
		printf("%d\n", total);
		sum += total;
		if (minn > total) minn = total;
		if (maxx < total) maxx = total;
		total = num = 0;
		for (i = 0; i < 54; ch[i++] = false);
	}

	printf("\n평균 : %f\n최소 : %d\n최대 : %d", (double)sum / 100000, minn, maxx);
}
