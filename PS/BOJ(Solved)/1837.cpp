/*
암호제작
https://www.acmicpc.net/problem/1837
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define p(a,b) make_pair((a), (b))
typedef long long ll;
using namespace std;

string p;
int k;
bool pn[1000007];
vector<int> prime;

int mod(int x)
{
	int ret = 0, len = p.size();
	for (int i = 0; i < len; i++) ret = (ret * 10 + (p[i] - '0')) % x;
	return ret;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> p >> k;
	int i, j;
	pn[0] = pn[1] = true;
	for (i = 2; i < k; i++) {
		if (!pn[i]) {
			prime.push_back(i);
			for (j = i * 2; j < k; j += i)
				pn[j] = true;
		}
	}
	for (auto it = prime.begin(); it != prime.end(); it++) {
		if (!mod(*it)) {
			cout << "BAD " << *it;
			return 0;
		}
	}
	cout << "GOOD";
}
