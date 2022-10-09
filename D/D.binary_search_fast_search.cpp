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
int BinarySearch_lb(int x, vi &a, int n)
{
    int l = -1; //a[l]<x
    int r = n;  //a[r]>=x
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (a[mid] < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return r + 1;
}
int BinarySearch_ub(int x, vi &a, int n)
{
    int l = -1; //a[l]<=x
    int r = n;  //a[r]>x
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (a[mid] <= x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l + 1;
}
void solve()
{
    int n, k;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    asort(a);
    cin >> k;
    while (k--)
    {
        int left, right;
        cin >> left >> right;
        int lb = BinarySearch_lb(left, a, n);
        int ub = BinarySearch_ub(right, a, n);
        cout << (ub - lb + 1) << " ";
    }
    return;
}
// This is also accepted
// void solve()
// {
//     int n, k;
//     cin >> n;
//     vi a(n);
//     rep(i, n) cin >> a[i];
//     asort(a);
//     cin >> k;
//     while (k--)
//     {
//         int l, r;
//         cin >> l >> r;
//         int lb = lower_bound(all(a), l) - a.begin();
//         int ub = upper_bound(all(a), r) - a.begin() - 1;
//         cout << (ub - lb + 1) << " ";
//     }
// }
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}