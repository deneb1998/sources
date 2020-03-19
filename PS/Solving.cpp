/*
큰 수 곱셈(2)
https://www.acmicpc.net/problem/15576
*/
#include <bits/stdc++.h>
#define INF ((1<<31) - 1)
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

string x, y;

//1:a>b 0:a=b -1:a<b
int cmp(string a, string b) {
	int la = a.size(), lb = b.size();
	if (la > lb) return 1;
	if (la < lb) return -1;
	for (int i = 0; i < la; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}
	return 0;
}

string add(string a, string b) {
	int i, j, tmp = 0;
	string ret;
	i = a.size() - 1;
	j = b.size() - 1;
	for (; i > -1 || j > -1;) {
		int a1 = 0, b1 = 0, s;
		if (i > -1) {
			a1 = a[i] - '0';
			i--;
		}
		if (j > -1) {
			b1 = b[j] - '0';
			j--;
		}
		s = a1 + b1 + tmp;
		ret.push_back((s % 10) + '0');
		tmp = s / 10;
	}
	if (tmp) ret.push_back(tmp + '0');
	reverse(ret.begin(), ret.end());
	return ret;
}

string mul(string a, string b) {
	if (cmp(a, b) == -1)
		swap(a, b);
	int la = a.size(), lb = b.size(), i, j, tmp;
	string ret = "0";
	for (i = lb - 1; i >= 0; i--) {
		int a1, b1, r;
		string ret2;
		b1 = b[i] - '0';
		tmp = 0;
		for (j = la - 1; j >= 0; j--) {
			a1 = a[j] - '0';
			r = a1 * b1 + tmp;
			ret2.insert(ret2.begin(), (r % 10) + '0');
			tmp = r / 10;
		}
		if (tmp)
			ret2.insert(ret2.begin(), tmp + '0');
		ret2.insert(ret2.end(), lb - 1 - i, '0');
		ret = add(ret, ret2);
	}
	return ret;
}

void give(string& a, int ind) {
	if (a[ind] > '0') {
		a[ind]--;
		return;
	}
	give(a, ind - 1);
	a[ind] += 9;
}

string sub(string a, string b) {
	int compare = cmp(a, b);
	if (!compare)
		return "0";
	if (compare == -1)
		swap(a, b);
	int la = a.size(), lb = b.size(), i;
	string ret;
	b.insert(0, la - lb, '0');
	for (i = la - 1; i >= 0; i--) {
		int a1 = a[i] - '0', b1 = b[i] - '0', tmp;
		if (a1 < b1) {
			give(a, i - 1);
			a1 += 10;
		}
		tmp = a1 - b1;
		ret.push_back(tmp + '0');
	}
	while (ret.back() == '0')
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	if (compare == -1)
		ret.insert(0, "-");
	return ret;
}

string karatsuba(string a, string b) {
	if (cmp(a, b) == -1)
		swap(a, b);
	string a1, a0, b1, b0, z0, z1, z2, r1, r2;
	int la = a.size(), lb = b.size(), m;
	if (lb < 9)
		return mul(a, b);
	m = lb / 2;
	a1 = a.substr(0, la - m); a0 = a.substr(la - m);
	b1 = b.substr(0, lb - m); b0 = b.substr(lb - m);
	z0 = karatsuba(a0, b0);
	z2 = karatsuba(a1, b1);
	z1 = sub(sub(karatsuba(add(a1, a0), add(b1, b0)), z2), z0);
	r1 = z2;
	r1.insert(r1.end(), 2 * m, '0');
	r2 = z1;
	r2.insert(r2.end(), m, '0');
	return add(r1, add(r2, z0));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> x >> y;
	cout << karatsuba(x, y);
}
