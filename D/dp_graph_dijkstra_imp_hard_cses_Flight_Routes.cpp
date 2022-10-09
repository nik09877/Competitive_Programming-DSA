#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
using pii = pair<int, int>;

int n, m, k;
vector<vector<pii>> g;
vector<vector<int>> dist;
const int INF = 9e15;

//dist[i][j] denotes the jth best distance to reach node i
void dijkstra()
{

    priority_queue<
        pii,
        vector<pii>,
        greater<pii>>
        pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[u][k - 1] < d)
            continue;

        for (auto e : g[u])
        {
            int v = e.first;
            int c = e.second;

            if (dist[v][k - 1] > c + d)
            {
                dist[v][k - 1] = c + d;
                pq.push({dist[v][k - 1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dist[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    dijkstra();

    for (int i = 0; i < k; ++i)
    {
        cout << dist[n][i] << " ";
    }
}