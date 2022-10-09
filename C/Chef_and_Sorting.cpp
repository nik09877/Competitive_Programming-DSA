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
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    rep1(i, n)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > a[i])
            cnt++;
    }
    int k = n / 2;
    if (cnt <= k)
    {
        prln(cnt);
        for (int i = 2; i <= n; i++)
        {
            if (a[i - 1] > a[i])
            {
                prsp(2);
                prsp(i);
                prln(a[i - 1] - a[i]);
            }
        }
        return;
    }
    int num = (1 << 30) - 1; //all set bits
    fo(i, 1, n)
    {
        a[i] ^= num;
    }
    cnt = 0;
    fo(i, 2, n)
    {
        if (a[i - 1] > a[i])
            cnt++;
    }
    prln(cnt + 1);
    cout << 3 << sp << n << sp << num << endl;
    fo(i, 2, n)
    {
        if (a[i - 1] > a[i])
        {
            prsp(2);
            prsp(i);
            prln(a[i - 1] - a[i]);
        }
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
