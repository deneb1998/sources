/*
철로
https://www.acmicpc.net/problem/13334
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
using namespace std;

ll n, h, o, d, ans, res;
ll cnt;

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

multiset<byA> msA; multiset<byA>::iterator s;
multiset<byB> msB; multiset<byB>::iterator e;

void move_s() {
	auto save = s;
	while (1) {
		if (s->b <= s->a + d)
			res--;
		s++;
		if (s == msA.end() || s->a != save->a)
			break;
	}
}

void move_b() {
	while (1) {
		while (e != msB.end() && e->a < s->a) {
			e++;
		}
		if (e == msB.end() || e->b > s->a + d || e->a < s->a || e->a >= s->a + d)
			break;
		res++;
		e++;
	}
	if (res > ans)
		ans = res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> h >> o;
		if (h > o) swap(h, o);
		msA.emplace(h, o);
		msB.emplace(h, o);
	}
	cin >> d;

	s = msA.begin();
	e = msB.begin();

	move_b();

	while (s != msA.end()) {
		move_s();
		if (s == msA.end())
			break;
		move_b();
	}
	cout << ans;
}
