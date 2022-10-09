#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
lli pre[100005];
lli dp[100005];
int k;

lli getAns(int n)
{
    //base case
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    //white flower
    if (n >= k)
        ans += getAns(n - k);

    //red flower
    ans += getAns(n - 1);

    return dp[n] = (ans) % mod;
}
void init()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 100000; i++)
    {
        pre[i] = pre[i - 1] + getAns(i);
        pre[i] %= mod;
    }
}
void solve()
{
    int a, b;
    cin >> a >> b;
    // lli ans = a == 1 ? pre[b] : (pre[b] - pre[a] + mod) % mod;
    lli ans = (pre[b] - pre[a - 1] + mod) % mod;
    cout << ans << endl;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t >> k;
    init();
    while (t--)
    {
        solve();
    }
}