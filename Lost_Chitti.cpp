#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pii pair<int, int>
#define pll pair<long, long>
#define plli pair<long long int, long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpii vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define vvlli vector<vector<long long int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int mod = 1000000007;

void solve()
{
    bool good = false;
    lli x1, y1, x2, y2, t, dist = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x1 == x2)
    {
        dist = abs(y1 - y2);
        if (t < dist)
            prln("No");
        else
            prln("Yes");
    }
    else if (y1 == y2)
    {
        dist = abs(x1 - x2);
        if (t < dist)
            prln("No");
        else
            prln("Yes");
    }
    else if (y2 < y1) //left movement
    {
        lli rowtime = abs(x1 - x2);
        x1 += rowtime;
        y1 -= rowtime;
        if (y1 == y2 || y1 + 1 == y2)
        {
            dist = rowtime;
            if (t < dist)
                prln("No");
            else
                prln("Yes");
        }
        else
        {
            dist += rowtime;
            dist += abs(y1 - y2);
            if (t < dist)
                prln("No");
            else
                prln("Yes");
        }
    }
    else if (y2 > y1)
    {
        lli rowtime = abs(x1 - x2);
        x1 += rowtime;
        y1 += rowtime;
        if (y1 == y2 || y1 - 1 == y2)
        {
            dist = rowtime;
            if (t < dist)
                prln("No");
            else
                prln("Yes");
        }
        else
        {
            good = true;
            dist += rowtime;
            dist += abs(y1 - y2);
            if (t < dist)
                prln("No");
            else
                prln("Yes");
        }
    }

    // prln(dist);
    // prln(good);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
