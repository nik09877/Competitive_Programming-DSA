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

//Euler circuit:
//  every node should have even degree
//  every node having deg>0 must be visited ie all the edges should belong to only one connected component

const int N = 1e5 + 5;
int n, m, deg[N];
vi path;
unordered_set<int> g[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = true;
    for (int child : g[node])
    {
        if (not vis[child])
            dfs(child);
    }
}

bool check_if_euler_circuit_possible()
{
    dfs(1);
    //case 1
    fo(i, 1, n)
    {
        if (not vis[i] and deg[i] > 0)
            return false;
    }
    //case 2
    fo(i, 1, n) if (deg[i] & 1) return false;

    return true;
}
void Euler_tour(int node)
{
    while (g[node].size() > 0)
    {
        int child = *g[node].begin();
        g[node].erase(child);
        g[child].erase(node);
        Euler_tour(child);
    }
    path.pb(node);
}
int32_t main()
{
    fastio;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    bool good = check_if_euler_circuit_possible();
    if (not good)
    {
        prln("IMPOSSIBLE");
        return 0;
    }
    Euler_tour(1);
    for (auto node : path)
        prsp(node);
}