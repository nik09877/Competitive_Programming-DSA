#include <bits/stdc++.h>
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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

// dp[L][R][0] -> maximum value of x in [L,R] if the current player is me
// dp[L][R][1] -> minimum value of x in [L,R] if the current player is not me because he will also play optimally

// maximize(x-y) = x-(sum-x) = 2*x-sum

ll dp[3003][3003][2];
void solve()
{
    int n;
    ll sum = 0;
    cin >> n;
    vi a(n);
    re(a, n);
    rep(i, n)
    {
        sum += a[i];
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);

            dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }
    ll x = dp[0][n - 1][0];
    prln(2 * x - sum);
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