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
#define int long long int
const int mod = 1000000007;

// dp[L][R] denotes the answer for the segment [L,R]

// base case:
// if there is only one element then dp[i][i] = 0

//divide into two segments

// for each k from L to R-1:
// dp[L][R] = min(dp[L][k]+dp[k+1][R]+sum[L][R])

// sum[L][R] = wt of left part + wt of right part
// sum[L][R] = prefix_sum[R]-prefix_sum[L-1]
// sum[L][R] = a[L] + sum[L+1][R] (exactly prefix sum but new trick)

//final answer = dp[0][n-1]
// O(n^3)
int dp[401][401], a[401], sum[401][401];
int32_t main()
{
    fastio;
    int n;
    cin >> n;
    //base case (If length of segment is 1)
    rep(i, n) cin >> a[i], dp[i][i] = 0, sum[i][i] = a[i];

    for (int len = 2; len <= n; len++)
    {
        for (int L = 0; L + len <= n; L++)
        {
            int R = L + len - 1;

            sum[L][R] = a[L] + sum[L + 1][R];
            dp[L][R] = MAXLL;

            for (int k = L; k < R; k++)
            {
                dp[L][R] = min(dp[L][R], dp[L][k] + dp[k + 1][R] + sum[L][R]);
            }
        }
    }
    prln(dp[0][n - 1]);
}