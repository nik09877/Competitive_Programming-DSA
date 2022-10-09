#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main()
{
    lli l, r, x, y;
    cin >> l >> r >> x >> y;

    if (y % x)
    {
        cout << 0;
        return 0;
    }

    lli p = y / x;
    lli cnt = 0;

    for (lli d = 1; d * d <= p; d++)
        if (p % d == 0)
        {
            lli c = p / d;
            if ((l <= c * x) && (c * x <= r) && (l <= d * x) && (d * x <= r) && (__gcd(c, d) == 1))
            {
                if ((d * d) == p)
                    cnt++;
                else
                    cnt += 2;
            }
        }

    cout << cnt;
}
