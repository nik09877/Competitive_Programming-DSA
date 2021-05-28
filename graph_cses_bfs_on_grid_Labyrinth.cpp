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
bool vis[1001][1001];
map<pii, pii> par;
string s[1001];
int n, m;

bool isValid(int x, int y)
{
    if (x < 0 or x >= n or y < 0 or y >= m or vis[x][y] == true or s[x][y] == '#')
        return false;
    return true;
}

void bfs(int s_x, int s_y)
{
    queue<pii> q;
    q.push({s_x, s_y});
    vis[s_x][s_y] = true;
    par[{s_x, s_y}] = {-1, -1};
    while (q.size())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        rep(i, 4)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                int new_x, new_y;
                new_x = x + dx[i];
                new_y = y + dy[i];
                vis[new_x][new_y] = true;
                par[{new_x, new_y}] = {x, y};
                if (s[new_x][new_y] == 'B')
                    return;
                q.push({new_x, new_y});
            }
        }
    }
}
int32_t main()
{
    fastio;
    cin >> n >> m;
    rep(i, n) cin >> s[i];
    int s_x, s_y, end_x, end_y;
    rep(i, n)
    {
        rep(j, m)
        {
            if (s[i][j] == 'A')
            {
                s_x = i;
                s_y = j;
            }
            else if (s[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    bfs(s_x, s_y);
    if (not vis[end_x][end_y])
    {
        no;
        return 0;
    }
    vector<char> ans;
    while (true)
    {
        pii p = par[{end_x, end_y}];
        auto par_x = p.ff, par_y = p.ss;
        if (par_x == -1 or par_y == -1)
            break;

        if (end_x == par_x - 1 and end_y == par_y)
            ans.push_back('U');
        else if (end_x == par_x + 1 and end_y == par_y)
            ans.push_back('D');
        else if (end_x == par_x and end_y == par_y + 1)
            ans.push_back('R');
        else if (end_x == par_x and end_y == par_y - 1)
            ans.push_back('L');

        end_x = par_x, end_y = par_y;
    }
    reverse(all(ans));
    yes;
    prln(sz(ans));
    for (char c : ans)
        pr(c);
}