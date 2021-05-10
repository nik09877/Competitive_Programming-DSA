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
#define ceil(numerator, denominator) return (numerator + denominator - 1) / denominator;
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
void solve()
{
    int n, op(0);
    cin >> n;
    int a[n + 5] = {0};
    set<pii> s;
    s.insert({n, -1});
    while (!s.empty())
    {
        op++;
        auto p = *s.rbegin();
        s.erase(p);
        int st = p.ss * -1;
        int len = p.ff;
        int end = st + len - 1;
        int mid = (st + end) / 2;
        a[mid] = op;
        if (mid - st)
        {
            s.insert({mid - st, -st});
        }
        if (end - mid)
        {
            s.insert({end - mid, -(mid + 1)});
        }
    }
    rep1(i, n)
    {
        cout << a[i] << sp;
    }
    cout << endl;
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