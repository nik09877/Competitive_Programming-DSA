#include <bits/stdc++.h>
#include <stdio.h>
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
struct edge
{
    int a, b, wt;
};
edge edges[200005];
int ans = 0;
class Dsu
{
public:
    int par[200005] = {0};
    int sz[200005] = {0};
    void make_set(int v)
    {
        par[v] = v;
        sz[v] = 1;
    }
    int find(int v)
    {
        if (v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    void merge(int a, int b, int w)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
            ans += w;
        }
    }
    void init(int n)
    {
        rep1(i, n)
        {
            make_set(i);
        }
    }
    bool comp(int a, int b)
    {
        return find(a) == find(b);
    }
};
bool cmp(edge &a, edge &b) { return a.wt < b.wt; }
void solve()
{
    Dsu ds;
    int n, m, a, b, w;
    cin >> n >> m;
    ds.init(n);
    rep(i, m)
    {
        cin >> a >> b >> w;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].wt = w;
    }
    sort(edges, edges + m, cmp);
    rep(i, m)
    {
        a = edges[i].a;
        b = edges[i].b;
        w = edges[i].wt;
        if (a != b)
            ds.merge(a, b, w);
    }
    cout << ans << endl;
    return;
}
int32_t main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}