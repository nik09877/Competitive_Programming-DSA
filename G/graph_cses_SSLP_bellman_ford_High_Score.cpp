#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;

const int INF = 1e17;
const int NINF = INF * (-1);

struct triplet
{
    int u;
    int v;
    int wt;
};

int n, m;
vector<triplet> edges;
vector<int> dist;

void bellman_ford()
{
    //Go on relaxing for n-1 times to get the distance from node 1 to all other nodes if there is no negative weight cycle
    for (int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            int u = e.u;
            int v = e.v;
            int w = e.wt;
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], w + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    }
    // if there is a negative cycle update all dist to NINF as eventually all will be NINF
    for (int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            int u = e.u;
            int v = e.v;
            int w = e.wt;
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + w < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1);
    edges.resize(m);
    for (int i = 0; i < m; ++i)
    {
        struct triplet inp;
        cin >> inp.u >> inp.v >> inp.wt;
        inp.wt *= -1;
        edges[i] = inp;
    }

    for (int i = 2; i <= n; ++i)
    {
        dist[i] = INF;
    }

    bellman_ford();
    if (dist[n] == NINF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[n] * (-1) << endl;
}