/*
부녀회장이 될테야
https://www.acmicpc.net/problem/2775
Algorithm : memoization
*/
#include <bits/stdc++.h>
using namespace std;

int t, b, n, a[17][17];

int main() {
	int i, j, k;
	cin >> t;
	for (i = 1; i < 15; i++)
		a[0][i] = i;
	for(i=1;i<15;i++)
		for (j = 1; j < 15; j++)
			for (k = 1; k <= j; k++) 
				a[i][j] += a[i - 1][k];
	while (t--) {
		cin >> b >> n;
		cout << a[b][n] << '\n';
	}
}
