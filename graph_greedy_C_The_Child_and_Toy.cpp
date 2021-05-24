#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
using namespace std;
vi graph[10001];
bool vis[10001];
vii cost;
int ar[10001];
int n, m;
int ans = 0;
bool comp(ii a, ii b)
{
    if (a.ff != b.ff)
        return a.ff > b.ff;
    else
        return graph[a.ss].size() > graph[b.ss].size();
}
void get_the_job_done()
{
    sort(cost.begin(), cost.end(), comp);
    for (int i = 0; i < cost.size() - 1; i++)
    {
        int v = cost[i].ss;
        int x = cost[i].ff;
        for (int j = 0; j < graph[v].size(); j++)
            if (!vis[graph[v][j]])
            {
                ans += ar[graph[v][j]];
            }
        vis[v] = 1;
    }
    cout << ans;
}
int main()
{
    int v, u, x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x, cost.pb({x, i}), ar[i] = x;
    for (int i = 0; i < m; i++)
        cin >> v >> u, graph[v].pb(u), graph[u].pb(v);
    get_the_job_done();
}
