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

int n, k;
int dp[2015][2015];

//!EDITORIAL
// here dp[i][j] denotes no of ways we can get a sequence of length i ending with number j ,1<=j<=n,
//1<=i<=k

// so dp[i][j] = summation of dp[i - 1][divisors of j <= n]

//ans = summation of dp[k][i] for all 1<=i<=n

void solve()
{
    cin >> n >> k;
    fo(i, 1, n)
    {
        dp[1][i] = 1;
    }
    for (int l = 1; l <= k - 1; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                //updating future value based on present value
                dp[l + 1][j] = (dp[l + 1][j] + dp[l][i]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[k][i]) % mod;
    }
    prln(ans);
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
