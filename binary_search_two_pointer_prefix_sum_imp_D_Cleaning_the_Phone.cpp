#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
/*
Let's say we remove x applications with bi=1 and y applications with bi=2. Obviously, among all the applications with bi=1, it was necessary to take x

maximum in memory (so we will clear the most memory).

Let's split all the applications into two arrays with bi=1
and bi=2

and sort them. Then you need to take a prefix from each array.

Let's iterate over which prefix we take from the first array. For it, we can uniquely find the second prefix (we remove applications until the sum exceeds m

). If we now increase the first prefix by taking a new application, then we don't need to take any applications in the second array. This means that when the first prefix is increased, the second one can only decrease.

To solve the problem, you can use the two-pointer method.

*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    vector<int> v(n);
    for (int &e : v)
    {
        cin >> e;
    }
    for (int &e : v)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            a.push_back(e);
        }
        else
        {
            b.push_back(e);
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll curSumA = 0;
    int r = (int)b.size();
    ll curSumB = accumulate(b.begin(), b.end(), 0ll);
    int ans = INT_MAX;
    for (int l = 0; l <= a.size(); l++)
    {
        while (r > 0 && curSumA + curSumB - b[r - 1] >= m)
        {
            r--;
            curSumB -= b[r];
        }
        if (curSumB + curSumA >= m)
        {
            ans = min(ans, 2 * r + l);
        }
        if (l != a.size())
        {
            curSumA += a[l];
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}