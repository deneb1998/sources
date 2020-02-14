/*
철로
https://www.acmicpc.net/problem/13334
*/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
class byA {
public:
	ll a, b;
	byA(ll a, ll b) :a(a), b(b) {}

	bool operator<(byA x) const {
		if (this->a != x.a)
			return this->a < x.a;
		return this->b < x.b;
	}
};
class byB {
public:
	ll a, b;
	byB(ll a, ll b) :a(a), b(b) {}

	bool operator<(byB x) const {
		if (this->b != x.b)
			return this->b < x.b;
		return this->a < x.a;
	}
};
multiset<byA> msA;
multiset<byB> msB;
ll n, a, b, d, res, ans, cnt;
bool isBeginContain = false;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		msA.emplace(a, b);
		msB.emplace(a, b);
	}
	cin >> d;
	auto it = msB.begin();
	auto begin = msA.begin();
	
	if (begin->b <= begin->a + d) {
		auto next = begin;
		cnt = 1;
		while (1) {
			next++;
			if (next == msA.end() || next->a != begin->a || next->b != begin->b)
				break;
			cnt++;
		}
		res += cnt;
		ans += cnt;
		begin = --next;
		isBeginContain = true;
	}
	while (it!=msB.end() && begin->a + d >= it->b) {
		if (isBeginContain && it->a == begin->a && it->b == begin->b)
			res--, ans--;
		res++, ans++;
		it++;
	}
	while (1) {
		isBeginContain = false;
		cnt = 1;
		auto next = begin;
		while (1) {
			if (next->b <= next->a + d)
				res--;
			next++;
			if (next == msA.end())
				break;
			if (next->a != begin->a) {
				begin = next;
				while (1) {
					next++;
					if (next == msA.end() || next->a != begin->a || next->b != begin->b)
						break;
					cnt++;
				}
				break;
			}
		}
		begin = next;
		if (next == msA.end())
			break;
		while (it!=msB.end() && begin->a + d >= it->b) {
			res++;
			it++;
		}
		if (res > ans)
			ans = res;
		if (it == msB.end())
			break;
	}
	cout << ans;
}
