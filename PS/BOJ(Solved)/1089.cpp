#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	char number[5][3];
	int check[10];
}node;

node floor1[10];

int n;

int floorCheck(node floor1[]) { 
	int i,j;
	for (i = 0; i < n; i++) {
		if (floor1[i].number[1][1] != '.' || floor1[i].number[3][1] != '.')
			return 1;

		for (j = 0; j < 10; j++) 
			floor1[i].check[j] = 0;

		if (floor1[i].number[0][0] == '#') {
			floor1[i].check[1] = 1;
		}
		if (floor1[i].number[0][1] == '#') {
			floor1[i].check[1] = 1; floor1[i].check[4] = 1;
		}
		if (floor1[i].number[1][0] == '#') {
			floor1[i].check[1] = 1;	floor1[i].check[2] = 1; floor1[i].check[3] = 1; floor1[i].check[7] = 1;
		}
		if (floor1[i].number[1][2] == '#') {
			floor1[i].check[5] = 1; floor1[i].check[6] = 1;
		}
		if (floor1[i].number[2][0] == '#') {
			floor1[i].check[1] = 1; floor1[i].check[7] = 1;
		}
		if (floor1[i].number[2][1] == '#') {
			floor1[i].check[1] = 1; floor1[i].check[0] = 1; floor1[i].check[7] = 1;
		}
		if (floor1[i].number[3][0] == '#') {
			floor1[i].check[1] = 1; floor1[i].check[3] = 1; floor1[i].check[4] = 1; floor1[i].check[5] = 1; floor1[i].check[7] = 1; floor1[i].check[9] = 1;
		}
		if (floor1[i].number[3][2] == '#') {
			floor1[i].check[2] = 1;
		}
		if (floor1[i].number[4][0] == '#' || floor1[i].number[4][1] == '#') {
			floor1[i].check[1] = 1; floor1[i].check[4] = 1; floor1[i].check[7] = 1;
		}
	}
	return 0;
}

double calc_result(node floor1[]) { 
	int i,j;
	double result = 0;

	for (i = 0; i < n; i++) {
		double a = 0, x = 0;
		for (j = 0; j < 10; j++) {
			if (floor1[i].check[j] == 0) {
				a += j; x++;
			}
		}
		result += ((a / x)*pow(10, n - (i + 1)));
	}

	return result;
}

int main() {
	scanf("%d", &n);
	int i,j,k;
	for (i = 0; i < 5;i++){
		char temp[40];
		scanf("%s", &temp);
		for (j = 0; j < n; j++) {
			for (k = 0; k < 3; k++) {
				if(j!=0)
					floor1[j].number[i][k] =temp[(j * 4) + k];
				else
					floor1[j].number[i][k] = temp[k];
			}
		}
	}

	if (floorCheck(floor1) == 1) {
		printf("%d", -1);
		return 0;
	}
	printf("%lf", calc_result(floor1));

	return 0;
}
