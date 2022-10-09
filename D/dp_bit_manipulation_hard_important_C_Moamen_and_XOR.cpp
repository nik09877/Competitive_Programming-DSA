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
#define int long long int
const int mod = 1000000007;
const int N = 2e5 + 5;

vi fact(N, 1);
int binPower(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
int mod_inv(int a, int m)
{
    return (binPower(a, m - 2) % mod + mod) % mod;
}
void precompute_factorial()
{
    for (int i = 2; i < N; i++)
        fact[i] = (i * fact[i - 1]) % mod;
}
int ncr(int n, int r)
{
    int a = fact[n];
    int b = mod_inv(fact[r], mod);
    int c = mod_inv(fact[n - r], mod);
    return ((((a * b) % mod) * c) % mod + mod) % mod;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        prln(1);
        return;
    }
    //precalc nc0+nc2+nc4+..+nc2m such that 2m<=n-1
    //it is the no. of ways to choose even no of indices to turn them on (make them 1 )
    int val = 0;
    for (int i = 0; i <= n - 1; i += 2)
    {
        val += ncr(n, i);
        val %= mod;
    }

    vvi dp(k, vi(2, 0));
    //LHS = a1 & a2 & ... & an
    //RHS = a1 Xor a2 Xor ... Xor an
    //dp[i][0]: LHS > RHS at ith bit  (for LHS ith bit is 1 and for RHS it is 0)
    //dp[i][1]: LHS == RHS at ith bit ( LHS-> 0 and RHS -> 0 or LHS-> 1 and RHS -> 1)
    for (int i = 0; i <= k - 1; i++)
    {
        //base case (if there is only one bit left)
        if (i == 0)
        {
            //if n is even => LHS = 1 and RHS = 0
            dp[i][0] = (n % 2 == 0 ? 1 : 0);

            //if n is odd => LHS = 1 and RHS = 1
            //Choose an even number of 1's and at least one 0 for LHS-> 0 and RHS -> 0
            dp[i][1] = (n % 2 == 1 ? 1 : 0) + val;

            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        else
        {
            dp[i][0] = ((n % 2 == 0 ? 1 : 0) * binPower(2, n * i)) % mod;

            dp[i][1] = (((n % 2 == 1 ? 1 : 0) + val) % mod * ((dp[i - 1][0] % mod + dp[i - 1][1]) % mod) % mod) % mod;
            ;

            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
    }

    int ans = (dp[k - 1][0] + dp[k - 1][1]) % mod;
    prln(ans);
    return;
}
int32_t main()
{
    fastio;
    precompute_factorial();
    int t;
    cin >> t;
    while (t--)
        solve();
}