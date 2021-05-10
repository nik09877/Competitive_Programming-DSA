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

lli n, k, l, r, mid, ans(-1);
vlli a;

lli segments(lli target)
{
    lli cnt(0), sum(0);
    repll(i, 0, n - 1)
    {
        if (a[i] > target)
            return k + 1;
        sum += a[i];
        if (sum > target)
        {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt;
}
void solve()
{
    cin >> n >> k;
    a.resize(n);
    repll(i, 0, n - 1) cin >> a[i], r += a[i];
    l = 0, r += 10000;
    // while (r > l + 1)
    // {
    //     mid = (l + r) / 2;
    //     if (segments(mid) <= k)
    //     {
    //         r = mid;
    //     }
    //     else
    //     {
    //         l = mid;
    //     }
    // }
    // cout << r << endl;
    while (l <= r)
    {
        mid = (l + r) / 2;
        lli seg = segments(mid);
        if (seg == k)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (seg > k)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
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