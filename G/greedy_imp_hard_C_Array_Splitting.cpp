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
// DEBUG TEMPLATE STARTS HERE//
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x);                    \
    cerr << "]" << endl;
#else
#define debug(x...)
#endif
//only for prime m
//DEBUG TEMPLATE ENDS HERE
// void compress(vi &a)
// {
//     //for fenwick tree
//     int n = sz(a);
//     map<ii> mpp, back;
//     int idx = 1;
//     rep(i, n)
//     {
//         if (mpp.find(a[i]) == mpp.end())
//         {
//             mpp.insert({a[i], idx});
//             back.insert({idx, a[i]}); //to get back original values
//             idx++;
//         }
//     }
//     rep(i, n)
//     {
//         a[i] = mpp[a[i]];
//     }
// }
// -----------POLICY BASED DATA STRUCTURES------------------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <class K, class V>
// using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
///---------------Functions---------------------///
template <class T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) { return (a * b) / __gcd(a, b); }
template <class T>
T ceil(T numerator, T denominator) { return (numerator + denominator - 1) / denominator; }
template <class T>
bool isPrime(T N)
{
    for (T i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
template <class T>
T cbrt(T x)
{
    T lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        T mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    if (hi * hi * hi <= x)
        return hi;
    else
        return lo;
}
template <class T>
T sqrt(T target)
{
    T l = 1, r = target;
    while (r > l + 1)
    {
        T m = (l + r) / 2;
        if (m * m <= target)
            l = m;
        else
            r = m;
    }
    return l;
}
template <class T>
T bin_power(T a, T b, T mod)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b = b >> 1;
    }
    return res;
}
int mod_inv(int a, int b) { return bin_power(a, b - 2, b); }
int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
///---------------custom_hash---------------------///
// class chash
// {
// public:
//     static uint64_t splitmix64(uint64_t x)
//     {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
//     // umap<lli, lli, custom_hash> mp;
// };
// ---------------variables-- ------------------- ///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// If you do not sacrifice for what you want, What you want becomes sacrifice.

#define int long long int
const int mod = 1000000007;

/*
basically u have to choose k-1 indexes from the array so that k subarray can be formed. now choose those k-1 indexes efficiently as ex. if k=3, so choose 2 indexes ,let it be i & j so cost is a[i]-a[0]+a[j]-a[i+1]+a[n]-a[j+1]. now write these terms efficiently so (a[i]-a[i+1])+(a[j]-a[j+1])+(a[n]-a[0]) now for to minimise this expression ,first two brackets should be min. as last bracket is always constant so sort the array(array of differences of a[i]-a[i+1]) and take 2 values (means if k=3) and then add (a[n]-a[0]).. this is yur minimum answer.

OR this is possible also

Let a[1], a[2].. a[n] be the elements in the array. Let 1 <= i < j < k < l....< n be the k-1 indices we choose for dividing the array into k segments. So, cost of division = (a[i] — a[1]) + (a[j] — a[i+1]) + .... + (a[k] — a[j+1]) + (a[n] — a[k+1]), on rearranging : (a[n] — a[1]) — ((a[i+1] — a[i]) + (a[j+1] — a[j]) +.....+ (a[k+1] — a[k])). So, we will store the difference of a[i+1]-a[i] for each 1<=i<n , sort them in decreasing order and take first k-1 differences and finally subtract from (a[n]-a[1]).

*/
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    re(a, n);
    if (k == n)
    {
        prln(0);
        return;
    }
    if (k == 1)
    {
        int mx = *max_element(all(a));
        int mn = *min_element(all(a));
        prln(mx - mn);
        return;
    }
    int ans = a[n - 1] - a[0];
    vi v;
    rep(i, n - 1)
    {
        v.pb(a[i] - a[i + 1]);
    }
    asort(v);
    rep(i, k - 1)
    {
        ans += v[i];
    }
    prln(ans);
    return;
}
int32_t main()
{
    fastio;
    solve();
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}