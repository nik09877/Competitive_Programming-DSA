#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))

const int mod = 1000000007;

int mpow(int base, int exp);
const int N = 1e5 + 4;

string go(string a, int l, int r, int k)
{
    int n = a.length();
    int len = r - l + 1;
    k = k % len;
    string b = a;
    int rem = len - k;

    int st = l, i;
    fo(i, k)
        b[l + i] = a[l + rem + i];
    fo(i, rem)
        b[l + k + i] = a[l + i];

    return b;
}
int main()
{
    int i, n, t;
    string a;
    cin >> a;
    cin >> n;
    while (n--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        a = go(a, l - 1, r - 1, k);
    }

    cout << a << endl;
    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}