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
lli dist[505][505];
lli n, m, q, a, b, w;
void warshall()
{
    for (lli k = 1; k <= n; k++)
    {
        for (lli i = 1; i <= n; i++)
        {
            for (lli j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--)
    {
        cin >> a >> b;
        if (dist[a][b] >= 1e18)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[a][b] << endl;
        }
    }
}
void solve()
{
    // cout << fixed << setprecision(10);
    cin >> n >> m >> q;
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= n; j++)
        {
            dist[i][j] = 1e18;
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for (lli i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        if (dist[a][b] != 0 and dist[a][b] >= w)
        {
            dist[a][b] = w;
            dist[b][a] = w;
        }
    }
    warshall();
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