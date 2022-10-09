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
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int INF = 1000000007;

int n, m;
bool isValid(int x, int y, vector<vector<char>> &s, vvi &dist)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (s[x][y] == 'B' || s[x][y] == 'E')
    {
        dist[x][y] = 0;
        return false;
    }
    // if (s[x][y] == 'C')
    // return true;
    return false;
}
int32_t main()
{
    fastio;
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    vvi dist(n, vi(m, INF)), vis(n, vi(m, 0));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> s[i][j];
        }
    }
    queue<pii> q;
    rep(i, n) rep(j, m) if (s[i][j] == 'E')
    {
        dist[i][j] = 0;
        q.push({i, j});
    }
    while (!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        fo(i, 0, 3)
        {
            if (isValid(x + dx[i], y + dy[i], s, dist))
            {
                // dist[x + dx[i]][y + dy[i]] = min(dist[x][y] + 1, dist[x + dx[i]][y + dy[i]]);
                dist[x + dx[i]][y + dy[i]] = 1 + dist[x][y];
            }
        }
    }
    rep(i, n)
    {
        rep(j, m) { (dist[i][j] == INF || dist[i][j] == 0) ? prsp(-1) : prsp(dist[i][j]); }
        cout << endl;
    }
}