#include <bits/stdc++.h>
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
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpi vector<pair<int, int>>
#define vvlli vector<vector<long long int>>
#define mod 1000000007
#define MAXLL 1e18
#define endl '\n'
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define input(a)    \
  for (auto &i : a) \
    cin >> i;
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s[1004];
bool vis[1004][1004];
int n, m;
bool isValid(int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == true || s[x][y] == '#')
    return false;
  return true;
}
void dfs(int x, int y)
{
  vis[x][y] = true;
  rep(i, 4)
  {
    if (isValid(x + dx[i], y + dy[i]))
    {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}
void solve()
{
  // cout << fixed << setprecision(10);
  cin >> n >> m;
  int ans = 0;
  rep(i, n)
  {
    cin >> s[i];
    rep(j, m)
    {
      vis[i][j] = false;
    }
  }
  rep(i, n)
  {
    rep(j, m)
    {
      if (!vis[i][j] && s[i][j] == '.')
      {
        ans++;
        dfs(i, j);
      }
    }
  }

  cout << ans;
  return;
}
int main()
{
  fastio;
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}