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
//--------------------------------------------------------------------//
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
int bin_power(int a, int b, int mod)
{
    int res = 1;
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
// ---------------variables-- ------------------- ///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// If you do not sacrifice for what you want, What you want becomes sacrifice.

#define int long long int
const int mod = 1000000007;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    vi r1(n + 1, 0), g1(n + 1, 0), b1(n + 1, 0), r2(n + 1, 0), g2(n + 1, 0), b2(n + 1, 0), r3(n + 1, 0), g3(n + 1, 0), b3(n + 1, 0);
    //r1[i] denotes if 1st index of our string is r what is the min changes we need to do
    //g2[i] denotes if 2nd index of our string is g what is the min changes we need to do
    //b3[i] denotes if 3rd index of our string is b what is the min changes we need to do

    //calc r1,g1,b1
    rep(i, n)
    {
        if (i % 3 == 0)
        {
            if (s[i] != 'R')
                r1[i] = 1;
            if (i - 1 >= 0)
                r1[i] += r1[i - 1];
        }
        else
            r1[i] += r1[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 0)
        {
            if (s[i] != 'G')
                g1[i] = 1;
            if (i - 1 >= 0)
                g1[i] += g1[i - 1];
        }
        else
            g1[i] += g1[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 0)
        {
            if (s[i] != 'B')
                b1[i] = 1;
            if (i - 1 >= 0)
                b1[i] += b1[i - 1];
        }
        else
            b1[i] += b1[i - 1];
    }
    //calc r2,g2,b2
    rep(i, n)
    {
        if (i % 3 == 1)
        {
            if (s[i] != 'R')
                r2[i] = 1;
            if (i - 1 >= 0)
                r2[i] += r2[i - 1];
        }
        else if (i - 1 >= 0)
            r2[i] += r2[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 1)
        {
            if (s[i] != 'G')
                g2[i] = 1;
            g2[i] += g2[i - 1];
        }
        else if (i - 1 >= 0)
            g2[i] += g2[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 1)
        {
            if (s[i] != 'B')
                b2[i] = 1;
            if (i - 1 >= 0)
                b2[i] += b2[i - 1];
        }
        else if (i - 1 >= 0)
            b2[i] += b2[i - 1];
    }
    //calc r3,g3,b3
    rep(i, n)
    {
        if (i % 3 == 2)
        {
            if (s[i] != 'R')
                r3[i] = 1;
            if (i - 1 >= 0)
                r3[i] += r3[i - 1];
        }
        else if (i - 1 >= 0)
            r3[i] += r3[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 2)
        {
            if (s[i] != 'G')
                g3[i] = 1;
            if (i - 1 >= 0)
                g3[i] += g3[i - 1];
        }
        else if (i - 1 >= 0)
            g3[i] += g3[i - 1];
    }
    rep(i, n)
    {
        if (i % 3 == 2)
        {
            if (s[i] != 'B')
                b3[i] = 1;
            if (i - 1 >= 0)
                b3[i] += b3[i - 1];
        }
        else if (i - 1 >= 0)
            b3[i] += b3[i - 1];
    }

    int ans = INT_MAX;
    for (int i = 0; i + k <= n; i++)
    {
        //case 1
        int t1 = r1[i + k - 1] + g2[i + k - 1] + b3[i + k - 1];
        if (i - 1 >= 0)
            t1 -= (r1[i - 1] + g2[i - 1] + b3[i - 1]);

        //case 2
        int t2 = g1[i + k - 1] + b2[i + k - 1] + r3[i + k - 1];
        if (i - 1 >= 0)
            t2 -= (g1[i - 1] + b2[i - 1] + r3[i - 1]);

        //case 3
        int t3 = b1[i + k - 1] + r2[i + k - 1] + g3[i + k - 1];
        if (i - 1 >= 0)
            t3 -= (b1[i - 1] + r2[i - 1] + g3[i - 1]);

        ans = min({ans, t1, t2, t3});
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
