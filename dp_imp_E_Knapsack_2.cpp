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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
// #define int long long
const int INF = 1000000007;
ll dp[2][100005]; //here taking size 2 means even and odd indices which is done for space optimization
int w[110];
int val[110];
void solve()
{
    int n, W;
    cin >> n >> W;
    rep(i, n)
    {
        cin >> w[i];
        cin >> val[i];
    }
    //dp[i][j]denotes minimum weight achieved using i elements and j is the maximum value possible such that dp[i][j]<=W
    for (int i = 1; i <= 100004; i++)
    {
        dp[0][i] = INF;
    }
    rep1(i, n)
    {
        int t = i % 2;
        rep(j, 100001) dp[t][j] = INF;
        rep(j, 100001)
        {
            dp[t][j] = min(dp[t][j], dp[!t][j]);
            if (j - val[i - 1] >= 0)
            {
                dp[t][j] = min(dp[t][j], dp[!t][j - val[i - 1]] + w[i - 1]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 100001; j++)
    {
        if (dp[n % 2][j] <= W)
            ans = j;
        // prsp(dp[n][j]);
    }
    cout << ans << endl;
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