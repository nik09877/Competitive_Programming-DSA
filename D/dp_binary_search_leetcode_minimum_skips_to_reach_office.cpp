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
    vector<int> D;
    long long s, last_dist;
    long long memo[1010][1010];

    long long getAns(int idx, int k)
    {
        if (idx < 0)
            return 0;

        long long &ans = memo[idx][k];
        if (ans != -1)
            return ans;

        //if we dont skip resting and decide to take rest until the next integral time
        long long d = getAns(idx - 1, k) + D[idx];
        //Round up the distance if it is not divisible by speed cuz we rest until the next integral time arrives
        if (d % s)
            d = ((d / s) + 1) * s;
        ans = d;

        //if we skip resting
        if (k > 0)
            ans = min(ans, getAns(idx - 1, k - 1) + D[idx]);
        return ans;
    }

    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size();
        D = dist, s = speed;

        long long dist_to_reach_office = hoursBefore * 1ll * s;
        last_dist = dist[n - 1];

        //if taking n skips we have to travel farther than office ie taking more time than hoursBefore
        long long d = 0;
        for (int x : dist)
            d += x;
        if (d / s > hoursBefore)
            return -1;

        memset(memo, -1, sizeof(memo));

        //binary search on the minimum no of skips so that we travel distance less than dist_to_reach_office ie             less time than hoursBefore
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;

            //find out using these many skips what is the minimum distance we can travel using first n-1 roads as                 we dont skip rest on the last road
            long long mn_dist = getAns(n - 2, mid) + last_dist;
            if (mn_dist <= dist_to_reach_office)
            {
                hi = mid;
            }

            else
                lo = mid + 1;
        }
        //not possible if n skips are required
        return lo == D.size() ? -1 : lo;
    }
};
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }
}