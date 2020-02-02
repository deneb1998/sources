/*
부분수열의 합 2
https://www.acmicpc.net/problem/1208
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, s, ls, rs;
vector<int> a, b;
vector<int> sum_a, sum_b;
long long ans;

long long calc(vector<int>::iterator& it, int sum, bool isA, int cnt) {
	if ((isA && it == a.end()) || (!isA && it == b.end())) {
		if (!cnt)
			return 0;
		if (isA)
			sum_a.push_back(sum);
		else
			sum_b.push_back(sum);
		if (sum == s)
			return 1;
		return 0;
	}
	long long x = calc(++it, sum, isA, cnt);
	--it;
	sum += *it;
	long long y = calc(++it, sum, isA, cnt+1);
	--it;
	return x + y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	int i, j, x;
	for (i = 0; i < n / 2; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (i = n / 2; i < n; i++) {
		cin >> x;
		b.push_back(x);
	}

	auto it = a.begin();
	ans += calc(it, 0, true, 0);
	it = b.begin();
	ans += calc(it, 0, false, 0);

	sort(sum_a.begin(), sum_a.end());
	sort(sum_b.begin(), sum_b.end());
	
	int lenA = sum_a.size(), lenB = sum_b.size();
	for (i = 0, j = lenB - 1; i < lenA && j >= 0;) {
		if (sum_a[i] + sum_b[j] == s) {
			if ((i + 1 < lenA && sum_a[i + 1] == sum_a[i]) || (j - 1 >= 0 && sum_b[j - 1] == sum_b[j])) {
				int cnt_a = 1, cnt_b = 1;
				for (i = i + 1; i < lenA; i++) {
					if (sum_a[i] != sum_a[i - 1])
						break;
					cnt_a++;
				}
				for (j = j - 1; j >= 0; j--) {
					if (sum_b[j] != sum_b[j + 1])
						break;
					cnt_b++;
				}
				ans += cnt_a * cnt_b;
			}
			else {
				ans++;
				i++;
			}
		}
		else if (sum_a[i] + sum_b[j] > s)
			j--;
		else
			i++;
	}
	cout << ans;
}
