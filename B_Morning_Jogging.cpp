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
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    vvi ans(n, vi(m, 0));
    vector<pair<int, pair<int, int>>> s;
    vi max_el_index;

    rep(i, n)
    {
        max_el_index.pb(m - 1);
    }
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
            s.push_back({a[i][j], {i, j}});
        }
        sort(a[i], a[i] + m);
    }
    sort(all(s));
    int c = 0;
    rep(i, m)
    {
        int row = s[i].ss.ff;
        int col = s[i].ss.ss;
        int val = s[i].ff;

        ans[row][c] = val;
        c++;
        fo(j, 0, m - 1)
        {
            if (a[row][j] == val)
            {
                a[row][j] = 0;
                break;
            }
        }
    }
    rep(i, n)
    {
        rep(j, m)
        {
            if (ans[i][j] == 0)
            {
                if (a[i][max_el_index[i]] != 0)
                    ans[i][j] = a[i][max_el_index[i]], max_el_index[i]--;

                else
                {
                    while (a[i][max_el_index[i]] == 0)
                        max_el_index[i]--;
                    ans[i][j] = a[i][max_el_index[i]], max_el_index[i]--;
                }
            }
        }
    }
    rep(i, n)
    {
        rep(j, m) prsp(ans[i][j]);
        cout << endl;
    }
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
