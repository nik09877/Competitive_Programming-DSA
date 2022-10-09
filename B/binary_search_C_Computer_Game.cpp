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
lli k, n, a, b, q;

lli printRes(lli l, lli r)
{
    lli res = 0;

    while (l <= r)
    {
        lli mid = (l + r) / 2;
        if (k - (mid * a + (n - mid) * b) > 0)
            res = mid, l = mid + 1;

        else
            r = mid - 1;
    }

    return res;
}
int main()
{
    cin >> q;

    while (q--)
    {
        cin >> k >> n >> a >> b;

        if (b * n >= k)
            cout << -1 << endl;

        else
            cout << printRes(0, n) << endl;
    }
}
