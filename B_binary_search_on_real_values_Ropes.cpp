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
#define pll pair<long, long>
#define plli pair<long long int, long long int>
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
#define input(a)      \
    for (auto &i : a) \
        cin >> i;
using namespace std;
bool sortbysec(pi a, pi b)
{
    return a.ss < b.ss;
}
int n, k;
vi a;
bool good(double len)
{
    int s(0);
    rep(i, n)
    {
        s += (a[i] / len);
    }
    return s >= k;
}
void solve()
{
    cout << fixed << setprecision(10);
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    double l = 0;   //good
    double r = 1e8; //bad
    //111111000000
    //l          r
    rep(i, 100)
    {
        double m = (l + r) / 2;
        if (good(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << endl;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}