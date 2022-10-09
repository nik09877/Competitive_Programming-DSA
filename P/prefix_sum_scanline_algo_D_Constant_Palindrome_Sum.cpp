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

//!EDITORIAL
//min value of sum can be 2 ,max can be k+k so x ranges from 2 -> 2*k

// cnt holds the sum that requires 0 changes in the n/2 pairs

//prefix[x]=no. of pairs requiring at most 1 change to get sum = x

//to create prefix array -> for each n/2 pair value of sum ranges from
// min(a[i],a[n-i-1])+1 to max(a[i],a[n-i-1])+k so do -> pre[l]++,pre[r+1]--,then
//take prefix sum;

//no of pairs that require 2 changes to get sum = x is -> n/2(total pairs) - pre[x](pairs requiring at most 1 change)

//for(i,2,2*k)
// ans = min(ans, pre[i]-cnt[i]+2*(n/2-pre[i]));

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<ii> cnt;
    rep(i, n)
    {
        cin >> a[i];
    }
    vi pre(2 * k + 2, 0);
    rep(i, n / 2)
    {
        ++cnt[a[i] + a[n - i - 1]];

        int l = min(a[i], a[n - i - 1]) + 1;
        int r = max(a[i], a[n - i - 1]) + k;
        pre[l]++, pre[r + 1]--;
    }

    fo(i, 1, 2 * k + 1)
    {
        pre[i] += pre[i - 1];
    }
    int ans = INT_MAX;
    fo(i, 2, 2 * k)
    {
        ans = min(ans, pre[i] - cnt[i] + 2 * (n / 2 - pre[i]));
    }
    prln(ans);
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
