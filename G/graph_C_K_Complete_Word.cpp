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

const int mod = 1000000007;

map<char, int> mp;
const int siz = 2e5 + 7;
string str;
vector<bool> visited;
vector<int> adj[siz];
void dfs(int &node, int &count)
{
    visited[node] = true;
    count += 1;
    mp[str[node]]++;
    for (int child : adj[node])
    {
        if (visited[child] == false)
            dfs(child, count);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> str;
    visited.clear();
    visited.resize(n + 5);
    for (int i = 0; i < n - k; i++)
    {
        if (i != (k + i))
        {
            adj[i].pb(k + i);

            adj[k + i].pb(i);
        }
        if (n - i - 1 != i)
        {
            adj[n - i - 1].pb(i);
            adj[i].pb(n - i - 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            mp.clear();
            int count = 0;
            dfs(i, count);
            int maxa = 0;
            for (auto it : mp)
            {
                maxa = max(maxa, it.ss);
            }
            ans += count - maxa;
        }
    }
    mp.clear();
    str.clear();
    for (int i = 0; i < n; i++)
        adj[i].clear();

    cout << ans << endl;
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

// DSU
// #define MAX 200010

// vi par, sz; vvi cnt;
// string str;
// int find_par(int v) {
//     if (v == par[v]) {
//         return v;
//     }

//     return par[v] = find_par(par[v]);
// }
// void merge(int u, int v) {
//     int a = find_par(u);
//     int b = find_par(v);
//     if (a != b) {
//         if (sz[a] < sz[b]) {
//             swap(a, b);
//         }
//         par[b] = a;
//         sz[a] += sz[b];
//         REP(i, 0, 26) {
//             cnt[a][i] += cnt[b][i];
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int test = 1;
//     cin >> test;
//     while (test--) {
//         int n, k; cin >> n >> k;
//         cin >> str;

//         cnt.assign(n, vi(26));
//         par.assign(n, 0); sz.assign(n, 0);
//         REP(i, 0, n) {
//             par[i] = i;
//             sz[i] = 1;
//             cnt[i][str[i] - 'a']++;
//         }
//         REP(i, 0, n) {
//             (i < n - i - 1 ? merge(i, n - i - 1) : void());
//             if (i + k <= n - 1) {
//                 merge(i, i + k);
//             }
//         }

//         int ans = 0;
//         /* REP(i, 0, n) {
//              cout << i << "->>";
//              REP(j, 0, 26) {
//                  cout << cnt[i][j] << " ";
//              }
//              cout << endl;
//          }*/

//         REP(i, 0, n) {
//             if (par[i] == i) {
//                 int mx = -1;
//                 REP(j, 0, 26) {
//                     mx = max(mx, cnt[i][j]);
//                 }
//                 ans += sz[i] - mx;
//             }
//         }

//         cout << ans << endl;

//     }

// }