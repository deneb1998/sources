/*
펠린드롬수
https://www.acmicpc.net/problem/1259
*/
#include <bits/stdc++.h>
#define INF ((1<<31) - 1)
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

string n;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n.size() == 1 && n[0] == '0') break;
		int i, j;
		bool yes = true;
		for (i = 0, j = n.size() - 1; i <= j; i++, j--) {
			if (n[i] != n[j]) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "yes" : "no") << '\n';
	}
}
