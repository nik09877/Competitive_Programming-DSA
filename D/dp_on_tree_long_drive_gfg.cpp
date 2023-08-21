#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define dsort(v) sort(v.rbegin(), v.rend())
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

In Geekland, there are 'n' cities connected by 'n - 1' bidirectional roads, forming a connected and weighted undirected tree. Geek wants to go on a long drive with Geekina, ensuring he visits each city at most once during the trip to avoid making Geekina angry.


Geek has 'q' possible options to start his trip, given in an array query[ ]. The task is to help Geek find the longest distance he can travel starting from each city given in the 'query' array.

Example:

edges[][] = [[1, 5, 3],
             [2, 5, 3],
             [1, 4, 2],
             [5, 3, 2]]
q = 4
query[] = [1, 3, 4, 5]
Output:
6 7 8 5
Explanation:
From city 1, longest distance is 1 -> 5 -> 2 = 6.
From city 3, longest distance is 3 -> 5 -> 1 -> 4 = 7.
From city 4, longest distance is 4 -> 1 -> 5 -> 2 = 8.
From city 5, longest distance is 5 -> 1 -> 4 = 5.

*/
// dp[i] stores first and second maximum path sum
class Solution
{
public:
#define ll long long
    vector<vector<ll>> graph[100001];
    long long dfs_sz(int u, int p, vector<pair<ll, ll>> &dp)
    {
        ll first_max = 0, second_max = 0;
        for (auto v : graph[u])
        {
            if (v[0] == p)
                continue;
            ll val_first = dfs_sz(v[0], u, dp) + v[1];

            if (val_first > first_max)
            {
                second_max = first_max;
                first_max = val_first;
            }
            else if (val_first > second_max)
            {
                second_max = val_first;
            }
        }

        dp[u].first = first_max;
        dp[u].second = second_max;

        return first_max;
    }

    void dfs(int u, int p, vector<pair<ll, ll>> &dp)
    {
        ll first_max = 0, second_max = 0;
        for (auto v : graph[u])
        {
            if (v[0] == p)
                continue;
            ll path_sum1 = dp[v[0]].first;
            ll path_sum2 = dp[v[0]].second;

            ll first_one = dp[u].first;
            ll second_one = dp[u].second;

            // cout<<"u "<<u<<" v "<<v[0]<<" "<<path_sum<<" "<<first_one<<" "<<second_one<<endl;

            if (first_one == path_sum1 + v[1])
            {
                if (second_one + v[1] > path_sum1)
                {
                    dp[v[0]].first = second_one + v[1];
                    dp[v[0]].second = path_sum1;
                }
                else
                {
                    dp[v[0]].first = path_sum1;
                    dp[v[0]].second = max(path_sum2, second_one + v[1]);
                }
            }
            else
            {
                if (first_one + v[1] > path_sum1)
                {
                    dp[v[0]].first = first_one + v[1];
                    dp[v[0]].second = path_sum1;
                }
                else
                {
                    dp[v[0]].first = path_sum1;
                    dp[v[0]].second = max(first_one + v[1], path_sum2);
                }
            }

            dfs(v[0], u, dp);
        }
    }

    vector<long long> longDrive(int n, vector<vector<int>> edges, int q, vector<int> query)
    {
        // code here
        // vector<vector<int>>graph[n];
        for (int i = 0; i < n - 1; i++)
        {
            ll u = edges[i][0];
            ll v = edges[i][1];
            ll w = edges[i][2];
            graph[u - 1].push_back({v - 1, w});
            graph[v - 1].push_back({u - 1, w});
        }
        vector<pair<ll, ll>> dp(n);

        dfs_sz(0, -1, dp);

        // for(int i=0; i<n; i++){
        //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
        // }

        dfs(0, -1, dp);

        vector<ll> ans;
        for (int i = 0; i < q; i++)
        {
            int val = query[i] - 1;
            // cout<<dp[val].second<<endl;
            ans.push_back(dp[val].first);
        }
        return ans;
    }
};

void solve()
{
    return;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();
}