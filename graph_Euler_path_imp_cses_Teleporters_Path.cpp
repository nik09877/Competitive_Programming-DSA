#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
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
#define vvi vector<vi>
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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

//Euler tour:
//  in[node]=out[node] for every node except
// 1: in[node]=out[node]+1(destination)
// 2: out[node]=in[node]+1(source)
//  every node having in_deg>0 or out_deg>0 must be visited ie all the edges should belong to only one strongly connected component

const int N = 200000;
int n, m;
bool vis[N];
int in[N], out[N];
vpii g[N];
vi path;

void Euler_tour(int node)
{
    while (g[node].size())
    {
        auto i = g[node].back();
        g[node].pop_back();
        if (vis[i.second])
            continue;
        vis[i.second] = 1; //mark this edge as erased
        Euler_tour(i.first);
    }
    path.push_back(node);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        out[u]++;
        in[v]++;
    }
    //case 1
    if (out[1] != in[1] + 1 || in[n] != out[n] + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    //case 2
    for (int i = 2; i < n; i++)
    {
        if (in[i] != out[i])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    Euler_tour(1);
    //case 3
    if (path.size() != m + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
    cout << "\n";
}
