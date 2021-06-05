#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int solve(const string &s, int x, int y)
{
    int res = 0;
    for (auto c : s)
        if (c - '0' == x)
        {
            ++res;
            swap(x, y);
        }
    if (x != y && res % 2 == 1)
        --res;
    return res;
}

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    forn(x, 10) forn(y, 10)
        ans = max(ans, solve(s, x, y));
    cout << sz(s) - ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}