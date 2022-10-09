#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

#define int long long int
const int mod = 1000000007;
int n, p, q, r, dp[100005][2][2][2], vis[100005][2][2][2];
vi a;

int go(int i, int c1, int c2, int c3)
{
    if (!c1 and !c2 and !c3)
        return 0;

    if (i == n)
    {
        if (!c1 and !c2 and !c3)
            return 0;
        return LLONG_MIN;
    }

    int &ans = dp[i][c1][c2][c3];
    if (vis[i][c1][c2][c3])
    {
        return ans;
    }
    vis[i][c1][c2][c3] = 1;

    ans = go(i + 1, c1, c2, c3);

    if (c1)
    {
        ans = max(ans, p * a[i] + go(i, 0, c2, c3));
    }
    if (!c1 and c2)
    {
        ans = max(ans, q * a[i] + go(i, 0, 0, c3));
    }
    if (!c1 and !c2 and c3)
    {
        ans = max(ans, r * a[i] + go(i, 0, 0, 0));
    }
    return ans;
}

int32_t main()
{
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> q >> r;
    a.resize(n);
    re(a, n);
    cout << go(0, 1, 1, 1);

    return 0;
}