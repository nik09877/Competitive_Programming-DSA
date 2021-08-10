#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

/*
If you do not sacrifice for what you want, What you want becomes the sacrifice.
1-Brute Force (complete search)(bitmask)(Number theory)
2-greedy sorting two pointer
3-Binary Search
4-dp
5-prefix sum
6-graph,bit manipulation(dependency)
7-segment tree (fenwick tree)

1-try going backward if given find A to B ,you find B to A
2-try out small test cases or do brute force solutions to find pattern
3- dont get stuck on only one approach
*/
#define int long long int
const int mod = 1000000007;

int n, k;
vpii a;

// Is it monotonic?
//no of elements less than x can be atmost k ie (cnt <= k) and no of elements less than x+1 will be > k ,so
// we found our break point and we just have to find the maximum x such that no. of elements less than x are <=k
bool good(int x)
{
    int cnt = 0;
    rep(i, n)
    {
        if (a[i].ff >= x)
            continue;
        //check if segment is completely < x or partially
        cnt += min(x - a[i].ff, a[i].ss - a[i].ff + 1);
    }
    return cnt <= k;
}
void solve()
{
    int l = 3e9, r = -3e9;
    cin >> n >> k;
    a.resize(n);
    rep(i, n)
    {
        cin >> a[i].ff >> a[i].ss;
        l = min(l, a[i].ff), r = max(r, a[i].ss);
    }
    int ans = -3e9;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (good(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    prln(ans);
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
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}