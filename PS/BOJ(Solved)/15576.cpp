/*
큰 수 곱셈(2)
https://www.acmicpc.net/problem/15576
*/

#include <bits/stdc++.h>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> cp;

void dft(vector<cp>& a, bool inv)
{
    int n = a.size();
    int i, j, k;
    for (i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (i = 1; i < n; i <<= 1)
    {
        double mypi = inv ? M_PI / i : -M_PI / i;
        cp wr(cos(mypi), sin(mypi));
        for (j = 0; j < n; j += i << 1)
        {
            cp w(1);
            for (k = 0; k < i; k++)
            {
                cp t = a[i + j + k] * w;
                a[i + j + k] = a[j + k] - t;
                a[j + k] += t;
                w *= wr;
            }
        }
    }
    if (inv) for (i = 0; i < n; i++) a[i] /= n;
}

void multiply(vector<cp>& a, vector<cp>& b)
{
    int n = max(a.size(), b.size()), i = 0;
    while ((1 << i) < (n << 1)) 
        i++;
    n = 1 << i;
    a.resize(n); b.resize(n);
    dft(a, 0); dft(b, 0);
    for (i = 0; i < n; i++) a[i] *= b[i];
    dft(a, 1);
}

int main()
{
    cin.tie(nullptr); cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s1, s2; cin >> s1 >> s2;
    vector<cp> a(s1.size()), b(s2.size());
    int i = s1.size();
    for (char x : s1) a[--i] = x - '0';
    i = s2.size();
    for (char x : s2) b[--i] = x - '0';

    multiply(a, b);
    int carry = 0, v;
    vi ans;
    for (cp x : a)
    {
        v = round(x.real()) + carry;
        carry = v / 10;
        ans.push_back(v % 10);
    }

    reverse(ans.begin(), ans.end());

    bool f = 0;
    for (int x : ans)
    {
        if (x) f = 1;
        if (f) cout << x;
    }
    if (!f) cout << 0;
    return 0;
}
