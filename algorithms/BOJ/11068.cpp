#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int t, a, s;
vector<int> b;

void func(int n) {
	int x = n;
	while(s) {
		b.push_back((s%x)/(x/n));
		s -= s%x;
		x *= n;
	}
}

bool isP() {
	int s = b.size();
	int isOdd = s % 2 == 0 ? 0 : 1;
	int mid = s / 2 - 1;
	for (int i = mid, j=1; i >= 0; i--, j++) 
		if (b[i] != b[mid + j + isOdd]) return false;
	return true;
}

int main() {
	cin >> t;
	int i;
	while (t--) {
		cin >> a;
		for (i = 2; i < 65; i++) {
			s = a;
			func(i);
			if (isP()) {
				cout << "1\n";
				b.clear();
				break;
			}
			b.clear();
		}
		if (i == 65) cout << "0\n";
	}
}
