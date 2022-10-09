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

#define int long long int
const int mod = 1000000007;
const int N = 1e5 + 5;
const int INF = 1e16;
vvi g[N];
int n, m;

// mn_flights_to_reach_cur_node_from_1st_node and
// mx_flights_to_reach_cur_node_from_1st_node using optimal path
// ways[i] denotes the number of ways we can reach current node

int mn_f[N], mx_f[N], dist[N], ways[N];

void dijkstra()
{
    fo(i, 1, n)
    {
        dist[i] = mn_f[i] = INF;
        mx_f[i] = INT_MIN;
    }

    //if there is only one node
    dist[1] = mn_f[1] = mx_f[1] = 0;
    ways[1] = 1;

    priority_queue<vi, vvi, greater<vi>> pq;
    pq.push({0, 1});

    while (pq.size())
    {
        int cur_node_dist = pq.top()[0];
        int cur_node = pq.top()[1];
        pq.pop();

        for (auto e : g[cur_node])
        {
            int child = e[0];
            int edge_wt = e[1];

            //we found a suboptimal route to child but we only need optimal routes
            if (cur_node_dist + edge_wt > dist[child])
                continue;

            //we have reached child before using another optimal route and we found another optimal route to reach it again.
            if (cur_node_dist + edge_wt == dist[child])
            {
                ways[child] += ways[cur_node];
                ways[child] %= mod;

                mn_f[child] = min(mn_f[child], 1 + mn_f[cur_node]);

                mx_f[child] = max(mx_f[child], 1 + mx_f[cur_node]);
            }

            //this is the first time we are going through an optimal path
            // previous optimal path was not actually optimal
            else if (cur_node_dist + edge_wt < dist[child])
            {
                ways[child] = 1 * ways[cur_node];
                ways[child] %= mod;

                mn_f[child] = 1 + mn_f[cur_node];

                mx_f[child] = 1 + mx_f[cur_node];

                dist[child] = cur_node_dist + edge_wt;

                pq.push({dist[child], child});
            }
        }
    }
    prsp(dist[n]);
    prsp(ways[n]);
    prsp(mn_f[n]);
    prsp(mx_f[n]);
}
int32_t main()
{
    fastio;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra();
}