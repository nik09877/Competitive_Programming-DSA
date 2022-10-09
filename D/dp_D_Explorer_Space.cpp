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

int dp[501][501][22];
int n, m, k;
int a[501][501], b[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

//!Editorial
//! a denotes left to right edge cost
//! b denotes up to down edge cost
//for each starting node it can go up,down,left,right. if we go anywhere add 2*cost of the edge to ans because we need to find : after k/2 steps what is the minimum cost we get and what is the node we have reached so that we can come back in this same path in the reverse direction to the starting node ,as it is given we need to reach starting node after exactly k steps

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}

int solve(int i, int j, int k)
{
    if (k == 0)
        return 0;

    int &res = dp[i][j][k];
    if (res != -1)
        return res;

    res = 1e9;

    for (int w = 0; w < 4; w++)
    {
        int x = i + dx[w], y = j + dy[w];

        if (check(x, y))
        {
            if (w == 0)
            {
                res = min(res, solve(x, y, k - 2) + 2 * (b[x][y]));
            }
            else if (w == 1)
            {
                res = min(res, solve(x, y, k - 2) + 2 * (a[x][y - 1]));
            }
            else if (w == 2)
            {
                res = min(res, solve(x, y, k - 2) + 2 * (b[x - 1][y]));
            }
            else
            {
                res = min(res, solve(x, y, k - 2) + 2 * (a[x][y]));
            }
        }
    }

    return res;
}

signed main()
{
    fastio;
    int tt = 1;
    while (tt--)
    {

        cin >> n >> m >> k;
        memset(dp, -1, sizeof dp);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> b[i][j];
        }

        if (k % 2)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << "-1"
                         << " ";
                cout << endl;
            }
        }
        else
        {

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (dp[i][j][k] == -1)
                        solve(i, j, k);

                    cout << dp[i][j][k] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}