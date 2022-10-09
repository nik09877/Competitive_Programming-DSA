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
const int mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vvi a(n, vi(n, 0));
    rep(i, n)
    {
        cin >> a[i][i];
    }
    rep(i, n)
    {
        int needed = a[i][i] - 1;
        int type = a[i][i];
        int row = i;
        int col = i;
        while (needed)
        {
            if (col - 1 >= 0 and a[row][col - 1] == 0)
            {
                col--;
                a[row][col] = type;
                needed--;
            }
            else if (row + 1 < n and a[row + 1][col] == 0)
            {
                row++;
                a[row][col] = type;
                needed--;
            }
            else
            {
                prln(-1);
                return;
            }
        }
    }
    rep(i, n)
    {
        rep(j, i + 1)
        {
            prsp(a[i][j]);
        }
        cout << endl;
    }
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
