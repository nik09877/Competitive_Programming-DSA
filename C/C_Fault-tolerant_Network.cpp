#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)

typedef long long li;

const int INF = int(1e9);

int n;
vector<int> a, b;

inline bool read()
{
    if (!(cin >> n))
        return false;
    a.resize(n);
    fore(i, 0, n)
            cin >>
        a[i];
    b.resize(n);
    fore(i, 0, n)
            cin >>
        b[i];
    return true;
}

int bestCandidate(const vector<int> &vals, int cur)
{
    int bst = INF + 10, pos = -1;
    fore(i, 0, n)
    {
        if (bst > abs(cur - vals[i]))
        {
            bst = abs(cur - vals[i]);
            pos = i;
        }
    }
    return pos;
}

inline void solve()
{
    li bst = 10ll * INF;

    vector<int> cds1 = {0, bestCandidate(b, a[0]), n - 1};
    vector<int> cds2 = {0, bestCandidate(b, a[n - 1]), n - 1};

    for (int var1 : cds1)
    {
        for (int var2 : cds2)
        {
            li ans = (li)abs(a[0] - b[var1]) + abs(a[n - 1] - b[var2]);

            if (var1 > 0 && var2 > 0)
                ans += abs(b[0] - a[bestCandidate(a, b[0])]);
            if (var1 < n - 1 && var2 < n - 1)
                ans += abs(b[n - 1] - a[bestCandidate(a, b[n - 1])]);

            bst = min(bst, ans);
        }
    }
    cout << bst << endl;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        read();
        solve();
    }
    return 0;
}