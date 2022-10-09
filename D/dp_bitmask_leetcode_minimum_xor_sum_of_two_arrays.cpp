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
int dp[14][(1 << 14)];
class Solution
{
public:
    int solve(int i, int mask, int &n, vector<int> &a, vector<int> &b)
    {
        if (i == n)
            return 0;

        if (dp[i][mask] != -1)
            return dp[i][mask];

        int answer = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
                answer = min(answer, (a[i] ^ b[j]) + solve(i + 1, (mask ^ (1 << j)), n, a, b));
        }

        return dp[i][mask] = answer;
    }
    int minimumXORSum(vector<int> &a, vector<int> &b)
    {
        memset(dp, -1, sizeof dp);
        int n = a.size();
        return solve(0, (1 << n) - 1, n, a, b);
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
}