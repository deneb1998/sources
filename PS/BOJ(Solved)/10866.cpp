/*
덱
https://www.acmicpc.net/problem/10866
Algorithm : Deque
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <memory.h>
#include <deque>
#define p(x) cout << (x) << '\n'
using namespace std;
typedef long long ll;

int n, x, len;
string o;
deque<int> d;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> o;
		if (o == "push_back") {
			cin >> x;
			len++;
			d.push_back(x);
		}
		else if (o == "push_front") {
			cin >> x;
			len++;
			d.push_front(x);
		}
		else if (o == "pop_front") {
			if (!len) p(-1);
			else {
				p(d.front());
				d.pop_front();
				len--;
			}
		}
		else if (o == "pop_back") {
			if (!len) p(-1);
			else {
				p(d.back());
				d.pop_back();
				len--;
			}
		}
		else if (o == "size")
			p(len);
		else if (o == "empty")
			p(len ? 0 : 1);
		else if (o == "front") {
			if (!len) p(-1);
			else p(d.front());
		}
		else {
			if (!len) p(-1);
			else p(d.back());
		}
	}
}
