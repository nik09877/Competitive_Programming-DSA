#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll MOD = 998244353;
typedef pair<ll, ll> ii;
#define iii pair<ll, ii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
vector<vector<ii>> adj;
int c[2];
int colour[200005];
bool ok;
void dfs(int node)
{
    c[colour[node]]++;
    for (auto child : adj[node])
    {
        if (colour[child.F] == -1)
        {
            colour[child.F] = colour[node] ^ child.S;
            dfs(child.F);
        }
        else if (colour[child.F] != (colour[node] ^ child.S))
        {
            /// impossible
            ok = false;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        adj.assign(n + 5, vector<ii>());
        f(i, 0, n + 5)
        {
            colour[i] = -1;
        }
        f(i, 0, m)
        {
            int a, b;
            string c;
            cin >> a >> b >> c;
            if (c == "crewmate")
            {
                /// same team
                adj[a].pb(ii(b, 0));
                adj[b].pb(ii(a, 0));
            }
            else
            {
                /// different team
                adj[a].pb(ii(b, 1));
                adj[b].pb(ii(a, 1));
            }
        }
        int ans = 0;
        ok = true;
        f(i, 1, n + 1)
        {
            if (colour[i] == -1)
            {
                colour[i] = 0;
                c[0] = c[1] = 0;
                dfs(i);
                ans += max(c[0], c[1]);
            }
        }
        if (!ok)
        {
            ans = -1;
        }
        cout << ans << "\n";
    }
}