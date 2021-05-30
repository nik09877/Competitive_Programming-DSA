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

class Solution
{
public:
    int dp[105][10005];
    int getAns(int e, int f)
    {
        if (e <= 1 || f <= 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int ans = INT_MAX, l = 1, r = f;
        while (l <= r)
        {
            int m = (l + r) >> 1, left, right, tempAns;

            //egg broke at mth floor
            left = getAns(e - 1, m - 1);
            //egg didn't break at mth floor
            right = getAns(e, f - m);

            //we need to take the worst case
            tempAns = 1 + max(left, right);
            //we need to minimize the maximum(worst case)attempts
            ans = min(ans, tempAns);

            //left part attempts are less tham right part then we need to consider right part
            if (left < right)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int e, int f)
    {
        memset(dp, -1, sizeof(dp));
        return getAns(e, f);
    }
} ans;

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        int e, f;
        cin >> e >> f;
        prln(ans.superEggDrop(e, f));
    }
}