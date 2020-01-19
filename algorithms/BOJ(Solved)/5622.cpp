/*
5622 다이얼
https://www.acmicpc.net/problem/5622
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;

string s;
int arr[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int sum = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
		sum += arr[s[i] - 65] + 1;
	cout << sum;
}
