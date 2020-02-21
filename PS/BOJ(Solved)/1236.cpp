/*
성 지키기
https://www.acmicpc.net/problem/1236
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
using namespace std;

int n, m, a[52], b[52];
char c;

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++) {
			scanf(" %c", &c);
			if (c != '.') 
				a[i] = b[j] = 1;
		}
	int aa, bb;
	aa = bb = 0;
	for (i = 0; i < n; i++)
		if (!a[i]) aa++;
	for (j = 0; j < m; j++)
		if (!b[j]) bb++;
	cout << max(aa, bb);
}
