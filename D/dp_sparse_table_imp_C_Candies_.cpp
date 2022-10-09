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
#define int long long int
using namespace std;
const int mod = 1000000007;
const int N = 1e5 + 5;
const int LOG = 17;
int a[N], n;
vector<vector<pii>> dp(20);

void solve()
{
    cin >> n;
    re(a, n);

    rep(i, n)
    {
        dp[0].push_back({a[i], 0}); //{remaining digit , candies}
    }

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            int dig1 = dp[j - 1][i].first;
            int dig2 = dp[j - 1][i + (1 << (j - 1))].first;
            int candies1 = dp[j - 1][i].second;
            int candies2 = dp[j - 1][i + (1 << (j - 1))].second;
            int res_candies = candies1 + candies2;
            int res_left = (dig1 + dig2) % 10;
            if (dig1 + dig2 >= 10)
                res_candies++;
            dp[j].push_back({res_left, res_candies});
        }
    }
    int q;
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        int len = (r - l + 1);
        int j = 0;
        while (len > 1)
        {
            j++;
            len /= 2;
        }
        cout << dp[j][l - 1].second << endl;
    }
    return;
}
int32_t main()
{
    fastio;
    solve();
}