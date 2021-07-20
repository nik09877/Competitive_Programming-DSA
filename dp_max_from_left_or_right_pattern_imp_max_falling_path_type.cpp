#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
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
/*
To further reduce the time complexity, I found that there is some similar calculation when we are trying to find the max. That is dp[i - 1][k] - k (or + k depends on the position). To reduce to the smaller problem, we assume that all the max value is from the left side of the current position. With this assumption, the abs(k - j) can be changed to j - k. Due to other values (e.g. points[i][j]) are fixed. The problem becomes to find the max dp[i - 1][k] + k in the left. That is

dp[i][j] = max(dp[i - 1][k] + k) + points[i][j] - j for all 0 <= k <= j

You may notice that some of the sign is reversed, that is because of we need to subtract the cost.

Now, the right side is similar. If we assume max value is from the right side. The relation will be:

dp[i][j] = max(dp[i - 1][k] - k) + points[i][j] + j for all j <= k <= points[i].size() - 1

The actual answer will be either from the left side or right side.*/

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &a)
    {
        int n = sz(a), m = sz(a[0]);
        ll dp[n][m];
        memset(dp, 0, sizeof(dp));

        rep(j, m)
            dp[0][j] = a[0][j];

        fo(i, 1, n - 1)
        {

            //max from left from prev_row
            vector<ll> left(m, 0);
            left[0] = dp[i - 1][0] + 0;
            fo(j, 1, m - 1)
            {
                left[j] = max(left[j - 1], dp[i - 1][j] + j);
            }

            //max from right from prev_row
            vector<ll> right(m, 0);
            right[m - 1] = dp[i - 1][m - 1] - (m - 1);
            rrep(j, m - 2, 0)
            {
                right[j] = max(right[j + 1], dp[i - 1][j] - j);
            }

            //for dp[i][j] maximum profit will be  max(left[j] - j, right[j] + j) + a[i][j]
            rep(j, m)
            {
                dp[i][j] = max(left[j] - j, right[j] + j) + a[i][j];
            }
        }

        ll ans = 0;
        rep(j, m) ans = max(ans, dp[n - 1][j]);
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
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
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}