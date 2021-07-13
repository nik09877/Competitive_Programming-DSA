#pragma GCC optimize("O3")
#pragma GCC target("sse4")
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

// If you do not sacrifice for what you want, What you want becomes the sacrifice.

#define int long long int
const int mod = 1000000007;
int dp[101][100002], a[100], n, k;

// dp[i][j] denotes the number of ways I can distribute j candies among i children (like knapSack)

// base case:(if there is only 1 element)
// for each j from 0 to k:
// dp[0][j]=1 //1 way to give j candies to one student

// for each j from 0 to k:
// dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][j-a[i]]

//current dp state depends upon prefix sum of previous state ie
// dp[i][j] =  prefix_sum[j]-prefix_sum[j-a[i]-1];

//dp[n-1][k] is the number of ways I can distribute k candies among n children

// complexity reduced from O(n*k^2) to O(n*k)

int32_t main()
{
    fastio;
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    if (k == 0)
    {
        prln(1);
        return 0;
    }

    //base case
    for (int j = 0; j <= a[0]; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        //calculate prefix_sum of previous dp state
        vi pre(k + 1, 0);
        for (int j = 0; j <= k; j++)
        {
            pre[j] = dp[i - 1][j];
            if (j - 1 >= 0)
                pre[j] += pre[j - 1];
            pre[j] %= mod;
        }

        //calculate current dp state
        for (int j = 0; j <= k; j++)
        {
            if (j - a[i] - 1 >= 0)
                dp[i][j] = (pre[j] - pre[j - a[i] - 1] + mod) % mod;
            else
                dp[i][j] = pre[j];
        }
    }

    prln(dp[n - 1][k]);
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}