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

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &grid)
    {
        vector<vector<pair<long long, long long>>> graph(n + 1);
        for (auto x : grid)
        { //creating adjacency list
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        long long INF = 1e15;
        long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<long long> dist(n + 1, INF);
        priority_queue<pair<long long, long long>> q;
        dist[0] = 0;
        dp[0] = 1; // initilize it to 1 since to reach 0 we have 1 way
        q.push({0, 0});
        while (q.size())
        {
            long long node = q.top().second;
            long long nodeWt = -q.top().first;
            q.pop();

            if (dist[node] < nodeWt)
                continue;
            for (auto key : graph[node])
            {
                long long child = key.first;
                long long childWt = key.second;
                if (nodeWt + childWt == dist[child])
                { // this is extra part other than classical Dijkstra
                    // we are adding parent's dp value to child's dp
                    dp[child] = (dp[child] + dp[node]) % MOD;
                }
                if (nodeWt + childWt < dist[child])
                {
                    dp[child] = dp[node] % MOD; // we are getting value of parent's dp
                    dist[child] = nodeWt + childWt;
                    q.push({-dist[child], child});
                }
            }
        }
        return dp[n - 1];
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