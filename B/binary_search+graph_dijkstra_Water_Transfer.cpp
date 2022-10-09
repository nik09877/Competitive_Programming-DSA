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

#define p1 pair<int, pair<int, int>>
int vis[405][405];
int a[405][405];
string dir[405];
int n, m, k, mid;

bool isValid(int x, int y, int capacity)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y])
        return false;
    if (capacity < mid)
        return false;
    return true;
}

bool good(int mid)
{
    //clear vis[i][j] matrix
    rep(i, n)
    {
        rep(j, m)
        {
            vis[i][j] = 0;
        }
    }
    priority_queue<p1, vector<p1>, greater<p1>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int x = t.ss.ff, y = t.ss.ss, op = t.ff;

        if (op > k)
            continue;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        if (x == n - 1 and y == m - 1)
            return 1;

        if (dir[x][y] == 'L')
        {
            if (isValid(x - 1, y, a[x][y] - 1))
                pq.push({op + 1, {x - 1, y}});

            if (isValid(x + 1, y, a[x][y] - 3))
                pq.push({op + 3, {x + 1, y}});

            if (isValid(x, y - 1, a[x][y]))
                pq.push({op, {x, y - 1}});

            if (isValid(x, y + 1, a[x][y] - 2))
                pq.push({op + 2, {x, y + 1}});
        }
        if (dir[x][y] == 'R')
        {
            if (isValid(x - 1, y, a[x][y] - 3))
                pq.push({op + 3, {x - 1, y}});

            if (isValid(x + 1, y, a[x][y] - 1))
                pq.push({op + 1, {x + 1, y}});

            if (isValid(x, y - 1, a[x][y] - 2))
                pq.push({op + 2, {x, y - 1}});

            if (isValid(x, y + 1, a[x][y]))
                pq.push({op, {x, y + 1}});
        }
        if (dir[x][y] == 'U')
        {
            if (isValid(x - 1, y, a[x][y]))
                pq.push({op, {x - 1, y}});

            if (isValid(x + 1, y, a[x][y] - 2))
                pq.push({op + 2, {x + 1, y}});

            if (isValid(x, y - 1, a[x][y] - 3))
                pq.push({op + 3, {x, y - 1}});

            if (isValid(x, y + 1, a[x][y] - 1))
                pq.push({op + 1, {x, y + 1}});
        }
        if (dir[x][y] == 'D')
        {
            if (isValid(x - 1, y, a[x][y] - 2))
                pq.push({op + 2, {x - 1, y}});

            if (isValid(x + 1, y, a[x][y]))
                pq.push({op, {x + 1, y}});

            if (isValid(x, y - 1, a[x][y] - 1))
                pq.push({op + 1, {x, y - 1}});

            if (isValid(x, y + 1, a[x][y] - 3))
                pq.push({op + 3, {x, y + 1}});
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m >> k;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    rep(i, n)
    {
        cin >> dir[i];
    }
    //Binary search on answer
    int l = 0, r = 1000000000, ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (good(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    prln(ans);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
