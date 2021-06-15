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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

class Solution
{
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        int n = boxes.size();

        //dp[i] -> minimum trips to deliver all i boxes
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        //two_pointer greedy + dp

        int l = 0, cur_weight = 0, trips = 2;

        for (int r = 0; r < n; r++)
        {
            cur_weight += boxes[r][1];

            if (r > 0 and boxes[r][0] != boxes[r - 1][0])
                trips++;

            while (cur_weight > maxWeight or r - l + 1 > maxBoxes or (l < r and dp[l] == dp[l + 1]))
            {
                cur_weight -= boxes[l][1];
                if (l < r and boxes[l][0] != boxes[l + 1][0])
                    trips--;
                l++;
            }

            //1 based indexing for dp
            dp[r + 1] = dp[l] + trips;
        }

        return dp[n];
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
