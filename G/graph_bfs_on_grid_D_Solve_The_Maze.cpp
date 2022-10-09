#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 55;
char en = '\n';
ll inf = 1e16;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod)
{
    ll res = 1;
    x %= mod;
    while (n)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
ll n, m;
char arr[N][N];
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(ll i, ll j) { return i >= 1 && i <= n && j >= 1 && j <= m; }
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;

        for (ll i = 1; i <= n; i++)
        {
            cin >> (arr[i] + 1);
        }

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (arr[i][j] == 'B')
                {
                    for (ll k = 0; k < 4; k++)
                    {
                        ll ni = i + dir[k][0];
                        ll nj = j + dir[k][1];
                        if (valid(ni, nj) && arr[ni][nj] == '.')
                            arr[ni][nj] = '#';
                    }
                }
            }
        }

        queue<pair<int, int>> que;
        bool visited[n + 5][m + 5];
        memset(visited, false, sizeof(visited));
        if (arr[n][m] == '.')
        {
            que.push({n, m});
            visited[n][m] = true;
        }
        while (!que.empty())
        {
            pair<ll, ll> curr = que.front();
            que.pop();
            for (ll k = 0; k < 4; k++)
            {
                ll ni = curr.first + dir[k][0];
                ll nj = curr.second + dir[k][1];

                if (valid(ni, nj) && !visited[ni][nj] && arr[ni][nj] != '#')
                {
                    que.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        bool good = true;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if ((arr[i][j] == 'G' && !visited[i][j]) or
                    (arr[i][j] == 'B' && visited[i][j]))
                {
                    good = false;
                    break;
                }
            }
        }
        cout << (good ? "Yes" : "No") << en;
    }

    return 0;
}