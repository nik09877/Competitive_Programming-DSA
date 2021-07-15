#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a) for (int i = a; i >= 0; i--)
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
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpi vector<pair<int, int>>
#define vvlli vector<vector<long long int>>
#define mod 1000000007
#define MAXLL 1e18
#define endl '\n'
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define input(a)      \
    for (auto &i : a) \
        cin >> i;
using namespace std;

const int MAX_N = 3e3 + 5;
const long long INF = 1e15 + 7;
int n, m, par[MAX_N];
vector<pair<ll, ll>> adj[MAX_N];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    //Go on relaxing for n times if during nth time distance of a node changes there is a negative weight cycle
    int cycle = 0;
    for (int i = 1; i <= n; i++)
    {
        cycle = 0;
        for (int u = 1; u <= n; u++)
        {
            for (auto e : adj[u])
            {
                ll v = e.ff;
                ll w = e.ss;
                if (dist[u] + w < dist[v])
                {
                    par[v] = u;
                    dist[v] = dist[u] + w;
                    cycle = v;
                }
            }
        }
    }

    if (!cycle)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        //presently the node we are at may or maynot be in the negative cycle so we go back n-1 times to make sure we are in the negative cycle
        for (int i = 0; i < n; i++)
        {
            cycle = par[cycle];
        }

        vi ans = {cycle};
        // for (int i = par[cycle]; i != cycle; i = par[i])
        // {
        //     ans.push_back(i);
        // }
        int u = par[cycle];
        while (u ^ cycle)
        {
            ans.pb(u);
            u = par[u];
        }
        ans.push_back(cycle);

        reverse(ans.begin(), ans.end());

        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
int main()
{
    fastio;
    solve();
    return 0;
}

// void Bellman_ford()
// {
//     ll x;
//     rep(i, n)
//     {
//         x = -1;
//         for (auto e : edg)
//         {
//             if (dist[e.a] != 1e18)
//             {
//                 if (dist[e.a] + e.w < dist[e.b])
//                 {
//                     dist[e.b] = dist[e.a] + e.w;
//                     par[e.b] = e.a;
//                     x = e.b;
//                 }
//             }
//         }
//     }
//     if (x == -1)
//     {
//         cout << "NO";
//     }
//     else
//     {
//         cout << "YES\n";
//         // rep(i, n)
//         // {
//         //     x = par[x];
//         // }
//         vector<ll> cycle;
//         for (int v = x;; v = par[v])
//         {
//             cycle.pb(v);
//             if (v == x and cycle.size() > 1)
//             {
//                 break;
//             }
//         }
//         reverse(all(cycle));
//         for (int v : cycle)
//         {
//             cout << v << " ";
//         }
//     }
// }