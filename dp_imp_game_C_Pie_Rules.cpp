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
// DEBUG TEMPLATE STARTS HERE//
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//DEBUG TEMPLATE ENDS HERE
///---------------Functions---------------------///
// template <class T>
// T gcd(T a, T b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// template <class T>
// T lcm(T a, T b)
// {
//     return (a * b) / __gcd(a, b);
// }
// template <class T>
// T max(T a, T b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// T min(T a, T b)
// {
//     if (a < b)
//         return a;
//     else
//         return b;
// }
// template <class T>
// T ceil(T numerator, T denominator)
// {
//     return (numerator + denominator - 1) / denominator;
// }
// template <class T>
// bool isPrime(T N)
// {
//     for (T i = 2; i * i <= N; ++i)
//     {
//         if (N % i == 0)
//             return false;
//     }
//     return true;
// }
// template <class T>
// T cbrt(T x) //cuberoot
// {
//     T lo = 1, hi = min(2000000ll, x);
//     while (hi - lo > 1)
//     {
//         T mid = (lo + hi) / 2;
//         if (mid * mid * mid < x)
//         {
//             lo = mid;
//         }
//         else
//             hi = mid;
//     }
//     if (hi * hi * hi <= x)
//         return hi;
//     else
//         return lo;
// }
// template <class T>
// T sqrt(T target)
// {
//     T l = 1, r = target;
//     while (r > l + 1)
//     {
//         T m = (l + r) / 2;
//         if (m * m <= target)
//             l = m;
//         else
//             r = m;
//     }
//     return l;
// }
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

// ---------------variables-- ------------------- ///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int mod = 1000000007;

/*//!EDITORIAL
This is a basic DP problem in which we have only two choices : either to choose the slice or to pass.

 

Let’s see from the point of view of whoever has decider token at the given point of time. Let’s start from the last element of the given array. Whoever has the decider token at last has to decide whether he wants to keep that slice or give it. As both players play optimally, obviously the decider token holder will keep that slice (as it is the last slice).

Now let’s come on the second last element of the array. Whoever has the decider token would have two choices - 1. He keeps the decider token and gives the slice to the other player. 2. He keeps the slice and gives the decider token to the other one. The decider token holder would obviously do what benefits him more so he would take the maximum of the two situations. For calculating that 1. We would maintain a decider array which shows the sum of sizes of slices the decider holder has at a given point. 2. A sum variable which counts the total sum of slices from the last to a given point. (Both from the last)

Now let’s come to the choices he has. For the 1st choice (i.e, he keeps the decider token), decider[i] would be equal to decider[i+1] because decider will keep the token so the size won’t affect. For the 2nd choice (i.e, he gives the token and keeps the slice), decider[i] would be equal to sum-decider[i+1]. So we have to take the max of these two and that would be our decider[i]. In this way the loop will iterate to 0.

So the answer would be decider[0] for Bob and sum-decider[0] for Alice.*/
void solve()
{
    int n;
    cin >> n;
    vlli a(n), token_holder(n, 0);
    rep(i, n) cin >> a[i];
    lli sum = a[n - 1];
    token_holder[n - 1] = a[n - 1];
    rrep(i, n - 2, 0)
    {
        sum += a[i];
        token_holder[i] = max(token_holder[i + 1], sum - token_holder[i + 1]);
    }
    prsp(sum - token_holder[0]);
    prsp(token_holder[0]);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
