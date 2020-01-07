#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

int n, h[100001];

ll func2(int s, int e, int mid) {
	int ns = mid, ne = mid + 1, nh = min(h[mid],h[mid+1]);
	ll size = 2 * nh;
	while (ns >= s && ne <= e) {
		if (ns == s && ne == e) break;
		if (ns > s && ne < e) {
			if (h[ns - 1] > h[ne + 1]) {
				ns -= 1; nh = min(nh,h[ns]);
			}
			else {
				ne += 1; nh = min(nh, h[ne]);
			}
		}
		else if (ns > s) {
			ns -= 1; nh = min(nh, h[ns]);
		}
		else if (ne < e) {
			ne += 1; nh = min(nh, h[ne]);
		}
		while (ns > s && h[ns - 1] >= nh) {
			ns--;
		}
		while (ne < e && h[ne + 1] >= nh) {
			ne++;
		}
		size = max(size, (ll)(ne - ns + 1)*(ll)nh);
	}
	return size;
}

ll func(int s, int e) {
	if (s == e) return h[s];
	int mid = (s + e) / 2;
	ll a = func(s, mid);
	ll b = func(mid + 1, e);
	ll c = func2(s, e, mid);
	return max(a, max(b, c));
}

int main() {
	int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; scanf("%d", h + i++));
    printf("%lld\n", func(1, n));
}
