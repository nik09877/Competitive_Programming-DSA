#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
#define eb emplace_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

/* find minimum t which satisfies max(|Xi-X|/Vi) <= t
ie for all Xi --> Xi-Vi*t <= X <= Xi+Vi*t must satisfy
so X must be in the intersection of all segments*/

vpii a; //{xi,vi}
int n;
bool good(double t)
{
    double lb = -1e18;
    double ub = 1e18;
    rep(i, n)
    {
        lb = max(lb, (a[i].ff - a[i].ss * t));
        ub = min(ub, (a[i].ff + a[i].ss * t));
    }
    return lb <= ub;
}
void solve()
{
    cout << fixed << setprecision(10);
    cin >> n;
    a.resize(n);
    rep(i, n)
    {
        cin >> a[i].ff;
    }
    rep(i, n)
    {
        cin >> a[i].ss;
    }
    double l = 0;   //bad
    double r = 1e9; //good
    rep(i, 100)
    {
        double mid = (l + r) / 2;
        if (good(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
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