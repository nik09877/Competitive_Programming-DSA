#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
// only for prime m
// DEBUG TEMPLATE ENDS HERE
//  void compress(vi &a)
//  {
//      //for fenwick tree
//      int n = sz(a);
//      map<ii> mpp, back;
//      int idx = 1;
//      rep(i, n)
//      {
//          if (mpp.find(a[i]) == mpp.end())
//          {
//              mpp.insert({a[i], idx});
//              back.insert({idx, a[i]}); //to get back original values
//              idx++;
//          }
//      }
//      rep(i, n)
//      {
//          a[i] = mpp[a[i]];
//      }
//  }
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

//  -----------POLICY BASED DATA STRUCTURES------------------------ ///
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <class K, class V>
// using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// ordered_multiset
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// NOTE
// find_by_order and order_of_key work the same as for a set.
// However for searching, lower_bound and upper_bound work oppositely. Also, let's say you want to erase x, use s.erase(s.upper_bound(x)) (as upper bound is considered as lower bound)

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
3-dont get stuck on only one approach
4-if given find substring ,go for hashing , prefix sum ,bit mask techniques
5-calculate contributtion of each element towards our answer
6-graph=tree + back edges (edges that connect to current node's ancestors)
7-insert duplicate values in set like pair<int,int> = <value, -index>
8-in multi source bfs think in reverse direction
9-bigger length can be divided into length of 2 and 3

dp patterns
1-dp[i] ->answer ending at i or using first i elements what is the answer
2-dp[i][j] -> using first i elements if current weight is j what is the answer
  here u can include ith element or not
3-unbounded knapsack,can include current element again or move to next element
4-dp(i,j) -> using first i and j elements of X and Y what is the answer (LCS)
5-for base case think if there is only one element or no element at all
6-to do an iterative version of recursive dp start iterating from back
*/

/*
EDITORIAL

1-DSU ON TREE METHOD O(N logN)

dist(u,v) <= a[v]
dist(v) - dist(u) <= a[v]
dist(u) >= dist(v) - a[v]
so for each node find answer for its children then find the number of children
such that dist(node) >= dist(child) - a[child]

intuition for this equation rearrangement
let's say you are at a node what values do you know about and what you don't
simply put all the values you know to one side of the equation.

2-BINARY LIFTING METHOD
you can also calculate for each node all its ancestors like u do in finding
LCA ie dp[i][j] denotes the (1<<j)th parent of i where max j = log(N)
So for each node calculate the answer for its ancestors in O(N logN)

*/
#define int long long int
const int mod = 1000000007;
const int N = 2e5 + 5;
ordered_multiset<int> *st[N];
int a[N], dist[N], ans[N];
vector<pii> g[N];

// merge childrens' set with the current node
void dfs(int node)
{
    int mx_node = -1, mx_size = 0;
    for (auto it : g[node])
    {
        int child = it.ff;
        int wt = it.ss;

        dist[child] = dist[node] + wt;
        dfs(child);

        if (st[child]->size() >= mx_size)
        {
            mx_size = st[child]->size();
            mx_node = child;
        }
    }
    if (mx_node == -1)
        st[node] = new ordered_multiset<int>();
    else
        st[node] = st[mx_node];

    // merge other children with the set
    for (auto it : g[node])
    {
        if (it.ff == mx_node)
            continue;
        for (auto val : *st[it.ff])
            st[node]->insert(val);
    }

    // calculate answer
    ans[node] += st[node]->order_of_key(dist[node] + 1);

    // insert current val
    st[node]->insert(dist[node] - a[node]);
}

void solve()
{
    int n;
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int par, wt;
        cin >> par >> wt;
        g[par].pb({i, wt});
    }
    dfs(1);
    fo(i, 1, n) prsp(ans[i]);
    return;
}

// #define int long long int
// const int mod = 1000000007;
// const int N = 2e5 + 5;
// ordered_multiset<int> st;
// int a[N], dist[N], ans[N];
// vector<pii> g[N];

// void dfs(int node)
// {
//     // answer before going into the child
//     int before = st.order_of_key(dist[node] + 1);

//     for (auto it : g[node])
//     {
//         int child = it.ff;
//         int wt = it.ss;

//         dist[child] = dist[node] + wt;

//         dfs(child);
//     }
//     // answer after coming out of the child
//     int after = st.order_of_key(dist[node] + 1);

//     // calculate answer
//     ans[node] += after - before;

//     // insert current val
//     st.insert(dist[node] - a[node]);
// }
int32_t main()
{
    fastio;
    solve();
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}