#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;
const int N = 1e5 + 5;

//Find the maximum edges we can remove so that remaining connected components have even no of nodes

vi g[N];
int subtree[N], ans;

void dfs(int node, int par)
{
    subtree[node] = 1;
    for (int child : g[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
        subtree[node] += subtree[child];

        //if subtree size of child is even we can remove the edges between parent and child
        if (subtree[child] % 2 == 0)
            ans++;
    }
}
void solve()
{
    int n;
    cin >> n;
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, -1);
    //if no of nodes is odd there is no way
    if (n & 1)
        prln(-1);
    else
        prln(ans);
    return;
}
int32_t main()
{
    fastio;
    solve();
}
