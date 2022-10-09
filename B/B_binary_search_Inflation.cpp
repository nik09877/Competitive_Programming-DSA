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

lli n, k;
vlli p, pre;

lli BinarySearch(lli up, lli down, lli r)
{
    lli ans = -1, l = 0;
    while (l <= r)
    {
        lli mid = (l + r) / 2;
        if (up % (down + mid) && up / (down + mid) == k)
        {
            l = mid + 1;
        }
        else if (up / (down + mid) > k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
void solve()
{

    lli sum = 0;
    cin >> n >> k;
    p.resize(n), pre.resize(n, 0);
    repll(i, 0, n - 1)
    {
        cin >> p[i];
        if (i == 0)
        {
            pre[0] = p[0];
        }
        else
        {
            pre[i] = p[i] + pre[i - 1];
        }
    }
    repll(i, 1, n - 1)
    {
        lli val, rem;
        rem = (p[i] * 100) % (pre[i - 1] + sum);
        if (rem)
        {
            val = (p[i] * 100) / (pre[i - 1] + sum) + 1;
        }
        else
        {
            val = (p[i] * 100) / (pre[i - 1] + sum);
        }

        if (val > k)
        {
            sum += BinarySearch(p[i] * 100, pre[i - 1] + sum, (p[i] * 100) - (pre[i - 1] + sum) + 100);
        }
    }
    cout << sum << endl;

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
