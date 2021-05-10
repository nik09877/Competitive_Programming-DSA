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
bool sortbysec(pi a, pi b)
{
    return a.ss < b.ss;
}

vi adj[100004];
bool vis[100004];
int dist[100004] = {0};
int par[100004];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    vis[node] = true;
    par[node] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int child : adj[node])
        {
            if (!vis[child])
            {
                vis[child] = true;
                dist[child] = dist[node] + 1;
                par[child] = node;
                q.push(child);
            }
        }
    }
}
void solve()
{
    // cout << fixed << setprecision(10);
    int n, m;
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1);
    if (dist[n] == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << dist[n] + 1 << endl;
        vi ans;
        int node = n;
        while (node)
        {
            ans.pb(node);
            node = par[node];
        }
        reverse(all(ans));
        for (int i : ans)
        {
            cout << i << " ";
        }
    }

    return;
}
int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}