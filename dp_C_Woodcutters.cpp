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
const int mod = 1000000007;

vpii a;
int dp[100005];
int n;
int getAns(int i, int occupied)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int x = 0, y = 0, z = 0;

    //falls to left
    if (a[i].ff - a[i].ss > occupied)
    {
        x = 1 + getAns(i + 1, a[i].ff);
    }
    //falls to right
    if (a[i].ff + a[i].ss < a[i + 1].ff)
    {
        y = 1 + getAns(i + 1, a[i].ff + a[i].ss);
    }
    //leave the tree as it is
    z = getAns(i + 1, a[i].ff);

    return dp[i] = max({x, y, z});
}
void solve()
{
    cin >> n;
    a.resize(n + 1);
    rep1(i, n)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    memset(dp, -1, sizeof(dp));

    prln(getAns(1, INT_MIN));
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
