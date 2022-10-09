#include <bits/stdc++.h>
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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;
int a[802][802];
int n, k;

bool good(int m)
{
    //check if there exists a submatrix such that median <= mid
    //conditions for this to happen:
    //let numMore be the amount of values strictly greater than mid
    //in a given submatrix
    //then, if numMore < (K ^ 2 / 2 + 1), the median is <= mid
    //to compute fast, use prefix sums

    vvi pre(n + 1, vi(n + 1, 0));
    rep1(i, n)
    {
        rep1(j, n)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (a[i][j] > m);
        }
    }
    for (int i = k; i <= n; i++)
    {
        fo(j, k, n)
        {
            int nums_having_cnt_more_than_median = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
            if (nums_having_cnt_more_than_median < (k * k / 2 + 1))
                return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> k;
    rep1(i, n) rep1(j, n) cin >> a[i][j];

    int l = 0, r = 1e9;
    rep(i, 30)
    {
        int m = (l + (r - l) / 2);
        if (good(m))
        {
            r = m;
        }
        else
            l = m + 1;
    }
    prln(r);
    return;
}
int32_t main()
{
    fastio;
    solve();
}