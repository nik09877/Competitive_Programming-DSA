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
4-if given find substring ,go for hashing , prefix sum ,bit mask techniques
5-calculate contributtion of each element towards our answer
6-graph=tree + back edges (edges that connect to current node's ancestors)
7-insert duplicate values in set like pair<int,int> = <value, -index>
8-in multi source bfs think in reverse direction
9-bigger length can be divided into length of 2 and 3

dp patterns
1- dp[i] ->answer ending at i or using first i elements what is the answer
2- dp[i][j] -> using first i elements if current weight is j what is the answer
   here u can include ith element or not
3- unbounded knapsack,can include current element again or move to next element
4- dp(i,j) -> using first i and j elements of X and Y what is the answer (LCS)
5- for base case think if there is only one element or no element at all
6- to do an iterative version of recursive dp start iterating from back
7- dp[i][j] denotes the maximum answer such that the 1st substring ends at i
   and 2nd substring ends at j. dp[i][j] = max(dp[i-1][j],dp[i][j-1])-1 or if
   s[i-1] == t[j-1] dp[i][j] = dp[i-1][j-1]+2
8- state optimization for even odd indices dp[n][m] -> dp[2][m] , do this, if    you only need previous row of dp
9- lets say u have parameter x in dp and its value can vary between [x-300,x+300]
   then use OFFSET technique where we need only dp[n][2*300] because we can calculate dp[i][original_x] as dp[i][original_x - OFFSET] where OFFSET = x-300
10- chceck if [continuous range from prev state is required],so [prefix sum] can be used for transition optimization,along with transition do prefix sum,take care of the order of execution.
11- If you see n<=500 it is dp on contiguous segment.
12- you can use map as dp table example -: vector<vector<map<ii>>>dp;
13- If answer can be negative keep visited array to check if we have cached the answer already instead of using if(ans!=-1)return ans;
*/

// #define int long long int
const int mod = 1000000007;

/*
First of all, for each closing bracket in our string let's define 2 values:

    d[j] = position of corresponding open bracket, or -1 if closing bracket doesn't belong to any regular bracket sequence.
     c[j] = position of earliest opening bracket, such that substring s(c[j], j) (both boundaries are inclusive) is a regular bracket sequence. Let's consider c[j] to be -1 if closing bracket doesn't belong to any regular bracket sequence.

It can be seen, that c[j] defines the beginning position of the longest regular bracket sequence, which will end in position j. So, having c[j] answer for the problem can be easily calculated.

Both d[j] and c[j] can be found with following algorithm, which uses stack.

    Iterate through the characters of the string.
    If current character is opening bracket, put its position into the stack.
    If current character is closing bracket, there are 2 subcases:

    Stack is empty - this means that current closing bracket doesn't have corresponding open one. Hence, both d[j] and c[j] are equal to -1.
    Stack is not empty - we will have position of the corresponding open bracket on the top of the stack - let's put it to d[j] and remove this position from the stack. Now it is obvious, that c[j] is equal at least to d[j]. But probably, there is a better value for c[j]. To find this out, we just need to look at the position d[j] - 1. If there is a closing bracket at this position, and c[d[j] - 1] is not -1, than we have 2 regular bracket sequences s(c[d[j] - 1], d[j] - 1) and s(d[j], j), which can be concatenated into one larger regular bracket sequence. So we put c[j] to be c[d[j] - 1] for this case.

    ANOTHER IDEA
    My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.

    And the DP idea is :

    If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

    Else if s[i] is ')'

        If s[i-1] is '(', longest[i] = longest[i-2] + 2

        Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

    For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
*/

// dp[i] denotes Longest Regular Bracket Sequence ending at i
// try to extend the bracket sequence

void solve()
{
    int n, mx = 0, cnt = 0;
    string s;
    cin >> s;
    n = sz(s);

    vi dp(n);
    stack<int> st;
    st.push(0);
    dp[0] = 0;
    fo(i, 1, n - 1)
    {
        if (s[i] == '(')
        {
            st.push(i);
            dp[i] = 0;
        }
        else
        {
            if (not st.empty())
            {
                if (s[st.top()] != '(')
                {
                    st.push(i);
                    dp[i] = 0;
                    continue;
                }

                int l = st.top();
                st.pop();
                int r = i;
                int len = r - l + 1;

                if (l - 1 >= 0 and s[l - 1] == ')' and dp[l - 1])
                    len += dp[l - 1];

                dp[i] = len;
                mx = max(mx, dp[i]);
            }
        }
    }
    if (mx == 0)
    {
        prsp(0);
        prln(1);
        return;
    }
    cnt = count(all(dp), mx);
    prsp(mx);
    prln(cnt);
    return;
}

// void solve()
// {
//     int n, mx = 0;
//     string st;
//     umap<ii, custom_hash> S, E, F;
//     F[0] = 1;
//     cin >> st;
//     n = sz(st);
//     stack<int> stk;
//     rep(i, n)
//     {
//         char c = st[i];
//         if (c == '(')
//         {
//             stk.push(i);
//         }
//         else
//         {
//             if (stk.empty())
//             {
//                 S[i] = E[i] = -1;
//             }
//             else
//             {
//                 int idx = stk.top();
//                 stk.pop();
//                 S[i] = E[i] = idx;
//                 if (idx > 0 && S[idx - 1] >= 0 && st[idx - 1] == ')')
//                 {
//                     E[i] = E[idx - 1];
//                 }
//                 int len = i - E[i] + 1;
//                 F[len]++;
//                 mx = max(mx, len);
//             }
//         }
//     }
//     cout << mx << sp << F[mx] << endl;
//     return;
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