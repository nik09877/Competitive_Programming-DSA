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
#define dsort(v) sort(v.rbegin(), v.rend())
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
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
4-if given find substring ,go for hashing, prefix sum, bit mask techniques, consider this index center of string and expand in odd/even length
5-calculate contribution of each element towards our answer
6-graph = tree + back edges (edges that connect to current node's ancestors)
7-insert duplicate values in set like pair<int,int> = <value, -index>
8-in multi source bfs think in reverse direction
9-bigger length can be divided into length of 2 and 3
10-divide the array into left part and right part,maybe for each i from [0,n-1] check if we can get answer from right part which we can store in map, or prefix array
11-For counting pairs use:-
    1-> use merge sort
    2-> use ordered_set
    3-> use coordinate compression + segment tree + point update + range sum query ( find number of elements in a given range)
12-In an array of (0's and 1's) or (+ve / -ve) you can group them as blocks of different colours.
13-If given you can add or subtract k from any element in the array any number of times to find mex,store them as val % k like
   0,1,2...,k-1,0,1,2...,k-1 which will form cycles and mex will be [cycle_length* min(freq[0..k-1]) + no of elements from 0 such that freq[i]>min_freq] -> [https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-41/6285056/problems/22853]
14-If given find valid sequence of length 3 or 4 consider each element as the middle element and check how many valid pairs are possible then
15- In finding pairs case i < j means i != j , maybe sorting it doesn't affect the order and you can fix one index say j and find all appropriate i's for this j
16- When you think about two pointer also think binary_search + sliding window/segment tree
17- when dealing with strings or characters know that there can be at max 26 chars , so calculate ans for each char
18- cnt of subarrays with sum = x => atmost(x) - atmost(x-1)
19- convert map[{row,col}] to an unique id ie. map[row + col*total_row_cnt]
20- sometimes visualizing the array values as points in a 2D graph helps in solving the problem
21- In tree problems think (top down or bottm up dp) or (re rooting dp) or
    ( consider path from each u to v via root or LCA) or (Euler tour + range query)
22- Whenever you see an equation try to rearrange it for your own benefit
23- max overlapping segments - store {startTime,+1} and {endTime,-1} in array
    and sort it and get maximum sum while looping the array or update [l,r] with +1 using dynamic lazy segTree
24- max non overlapping segments - sort by finish time
25- When you think here segTree can be used but array size crosses Memory Limit ,
    think segtree+coordinate compression or dynamic lazy segTree
26- If the queries are already given, you can sort the queries acc to your liking
    and store their answers in an order
27- While finding shortest path using bfs,we keep a set of unvisited nodes,we iterate on the set,
    after going to an unvisited node, remove it from the unvisited set.
28- If you want to find something for each distinct value of an array then store it in map<int,vector<int>> index array and find answer for each value.
29- If you are dealing with circular/rotational array or string use arr+arr or str+str to use two pointer or string algorithms.
30- Think about using stack if your array needs to be reduced by some operation which can reduce multiple subarrays at a time or
for each value at an index it can remove the top element of stack based on certain condition.
31- Use Binary Lifting when (a node can have only one child/functional graph) or it is a tree i.e dp[i][j] denotes (2^j)th parent/child of current node and a distance d can be divided into binary lifts of powers of 2
32- Use meet in the middle when the array can be split in 2 parts and for each subset in 1st part find how much you can take from 2nd part to optimize answer
33- If you have to find max or min length subsequence for a given condition you can sort the array, but in case of permutation (if the order matters) you can't sort the array.
34- While going through each subarray to calculate answer for each subarray , you can actually calculate answer on the go while moving the j pointer forward.
35- Store freq of freq to keep track of max_freq in case of dynamic update in an array
36- If given find A you find A' i.e max -> find min, at_most_k -> at_least_k+1, equal_to_k = at_most(k) - at_most(k-1)
37- If you want to maximize the (product of (sum of nums equal to target)), then divide target in powers of 3 and 2.

dp patterns
1- dp[i] ->answer ending at i or using first i elements what is the answer
   (store prev dp values in segtree + coordinate compression and get max prev dp)
2- dp[i][j] -> using first i elements if current weight is j what is the answer
   here u can include ith element or not
3- unbounded knapsack,can include current element again or move to next element
4- dp(i,j) -> using first i and j elements of X and Y what is the answer (LCS)
5- for base case think if there is only one element or no element at all
6- to do an iterative version of recursive dp start iterating from back
7- dp[i][j] denotes the maximum answer such that the 1st substring ends at i
   and 2nd substring ends at j. dp[i][j] = max(dp[i-1][j],dp[i][j-1])-1 or if
   s[i-1] == t[j-1] dp[i][j] = dp[i-1][j-1]+2
8- state optimization for even odd indices dp[n][m] -> dp[2][m] , do this, if you only need previous row of dp
9- lets say u have parameter x in dp and its value can vary between [x-300,x+300]
   then use OFFSET technique where we need only dp[n][2*300] because we can calculate dp[i][original_x] as dp[i][original_x - OFFSET] where OFFSET = x-300
10- check if [continuous range from prev state is required],so [prefix sum] can be used for transition optimization,along with transition do prefix sum,take care of the order of execution.
11- If you see n<=500 it is dp on contiguous segment (compress them to groups variation also).
12- you can use map as dp table example -: vector<vector<map<ii>>>dp;
13- If answer can be negative keep visited array to check if we have cached the answer already instead of using if(ans!=-1)return ans;
14- Sometimes if constraints are large your dp state can have ans as a parameter,
    check if dp[n][ans] is possible or not, for ans in range [1,max_possible_ans]
    such that it satisfies certain condition.
15- sometimes in dp on trees problems when storing max or min in dp[node] you should store 2 max or min values (i.e dp[node][2]) so that even if you have to remove the max/min path , you can get the next best max/min along a path.
16- dp[i][j] = cur_cost + dp[i+1][j-1]
17- If you are standing at i and you have to find out cost[i] then cost[i] = cost to get to i-1 + cost to get to i from i-1 or cost[i] = cost to get to i+1 + cost to get to i from i+1
18- cnt distinct subsequences -> dp[i]  = dp[i-1] * 2 - dp[last_pos[s[i]]];
*/

#define int long long int
const int mod = 1000000007;

const int N = 1e5 + 5;
const int maxD = 18;
int n;
pii dist[N];
int LCA[N][maxD + 1];
vpii g[N];
int lvl[N];
void dfs(int node, int par, pii d, int level)
{
    dist[node] = d;
    LCA[node][0] = par;
    lvl[node] = level;
    for (auto child : g[node])
    {
        if (child.ff == par)
            continue;
        pii new_d = d;
        int cost = child.ss;
        while (cost % 2 == 0)
        {
            new_d.ff += 1;
            cost /= 2;
        }
        while (cost % 5 == 0)
        {
            new_d.ss += 1;
            cost /= 5;
        }
        dfs(child.ff, node, new_d, level + 1);
    }
}

void preprocess_LCA()
{
    dfs(1, -1, mkp(0, 0), 0);

    for (int j = 1; j <= maxD; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}

int get_LCA(int a, int b)
{
    if (lvl[a] > lvl[b])
        swap(a, b);

    int d = lvl[b] - lvl[a];

    while (d > 0)
    {
        int msb = log2(d);
        b = LCA[b][msb];
        d -= (1 << msb);
    }
    if (a == b)
        return a;

    for (int i = maxD; i >= 0; i--)
    {
        if (LCA[a][i] != -1 and LCA[a][i] != LCA[b][i])
        {
            a = LCA[a][i], b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

pii get_dist(int a, int b)
{
    int lca = get_LCA(a, b);
    return mkp(dist[a].ff + dist[b].ff - 2 * dist[lca].ff, dist[a].ss + dist[b].ss - 2 * dist[lca].ss);
}

void solve()
{
    int q;
    cin >> n >> q;
    rep(i, n - 1)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].pb({b, wt});
        g[b].pb({a, wt});
    }
    preprocess_LCA();
    int u, v;
    while (q--)
    {
        cin >> u >> v;
        pii cost = get_dist(u, v);
        prln(min(cost.ff, cost.ss));
    }
    return;
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}