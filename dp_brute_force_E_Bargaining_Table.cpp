// #include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define rrep(i, a, b) for (int i = a; i >= b; i--)
// #define rep1(i, n) for (int i = 1; i <= n; i++)
// #define fo(i, a, n) for (int i = a; i <= n; i++)
// #define repll(i, a, n) for (lli i = a; i <= n; i++)
// #define mkp make_pair
// #define pb emplace_back
// #define ff first
// #define ss second
// #define ll long long
// #define lli long long int
// #define ii int, int
// #define pii pair<int, int>
// #define pll pair<long, long>
// #define plli pair<long long int, long long int>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vlli vector<long long int>
// #define vpii vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define vvlli vector<vector<long long int>>
// #define MAXLL 1e18
// #define endl '\n'
// #define sp ' '
// #define dsort(v) sort(v.begin(), v.end(), greater<int>())
// #define asort(v) sort(v.begin(), v.end())
// #define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
// #define all(v) v.begin(), v.end()
// #define umap unordered_map
// #define uset unordered_set
// #define sz(x) ((int)(x).size())
// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pr(x) cout << x
// #define prsp(x) cout << x << sp
// #define prln(x) cout << x << endl
// #define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
// #define re(a, n)   \
//     rep(i, n)      \
//             cin >> \
//         a[i];
// using namespace std;
// // DEBUG TEMPLATE STARTS HERE//
// typedef unsigned long long ull;
// typedef long double lld;
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// void _print(ll t) { cerr << t; }
// void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(ull t) { cerr << t; }

// template <class T, class V>
// void _print(pair<T, V> p);
// template <class T>
// void _print(vector<T> v);
// template <class T>
// void _print(set<T> v);
// template <class T, class V>
// void _print(map<T, V> v);
// template <class T>
// void _print(multiset<T> v);
// template <class T, class V>
// void _print(pair<T, V> p)
// {
//     cerr << "{";
//     _print(p.ff);
//     cerr << ",";
//     _print(p.ss);
//     cerr << "}";
// }
// template <class T>
// void _print(vector<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(set<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(multiset<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T, class V>
// void _print(map<T, V> v)
// {
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// // void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// #ifndef ONLINE_JUDGE
// #define debug(x...)               \
//     cerr << "[" << #x << "] = ["; \
//     _print(x)
// #else
// #define debug(x...)
// #endif
// //only for prime m
// //DEBUG TEMPLATE ENDS HERE
// // void compress(vi &a)
// // {
// //     //for fenwick tree
// //     int n = sz(a);
// //     map<ii> mpp, back;
// //     int idx = 1;
// //     rep(i, n)
// //     {
// //         if (mpp.find(a[i]) == mpp.end())
// //         {
// //             mpp.insert({a[i], idx});
// //             back.insert({idx, a[i]}); //to get back original values
// //             idx++;
// //         }
// //     }
// //     rep(i, n)
// //     {
// //         a[i] = mpp[a[i]];
// //     }
// // }
// ///---------------custom_hash---------------------///
// // class chash
// // {
// // public:
// //     static uint64_t splitmix64(uint64_t x)
// //     {
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }

// //     size_t operator()(uint64_t x) const
// //     {
// //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// //         return splitmix64(x + FIXED_RANDOM);
// //     }
// //     // umap<lli, lli, custom_hash> mp;
// // };
// //--------------------------------------------------------------------//
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace __gnu_pbds;
// // template <class T>
// // using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// // template <class K, class V>
// // using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// ///---------------Functions---------------------///
// template <class T>
// T gcd(T a, T b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b % a, a);
// }
// template <class T>
// T lcm(T a, T b) { return (a * b) / __gcd(a, b); }
// template <class T>
// T ceil(T numerator, T denominator) { return (numerator + denominator - 1) / denominator; }
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
// T cbrt(T x)
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
// ll expo(ll a, ll b, ll mod)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = (res * a) % mod;
//         a = (a * a) % mod;
//         b = b >> 1;
//     }
//     return res;
// }
// ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
// ll mod_add(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mod_mul(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll mod_sub(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mod_div(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (mod_mul(a, mminvprime(b, m), m) + m) % m;
// }
// //------------------------------------------------------------------------------------------------//
// // ---------------variables-- ------------------- ///
// // const int dx[4] = {-1, 1, 0, 0};
// // const int dy[4] = {0, 0, -1, 1};
// // int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// // int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int mod = 1000000007;

// void solve()
// {
//     int n, m;
//     ll mx = -9e9;
//     cin >> n >> m;
//     bool dp[25][25][25][25] = {false};
//     vvi grid(n, vi(m));

//     rep(i, n)
//         rep(j, m)
//     {
//         char ch;
//         cin >> ch;
//         grid[i][j] = ch - '0';
//         dp[i][j][i][j] = (grid[i][j] == 0);
//     }
//     // EDITORIAL
//     // considering rectangle starting coords ->[x1,y1] and ending coords->[x2,y2]
//     // it is possible to make this rectangle if dp[x1][y1][x2-1][y2] and dp[x1][y1][x2][y2-1] is possible

//     //considering rectangles having single row
//     for (int x = 0; x < n; x++)
//         for (int y1 = 0; y1 < m; y1++)
//         {
//             for (int y2 = y1 + 1; y2 < m; y2++)
//             {
//                 if (not grid[x][y2] and dp[x][y1][x][max(y2 - 1, 0)])
//                 {
//                     dp[x][y1][x][y2] = true;
//                     ll curr_perimeter = 2 * ((1) + (y2 - y1 + 1));
//                     mx = max(mx, curr_perimeter);
//                 }
//             }
//         }
//     //considering rectangles having single column
//     for (int y = 0; y < m; y++)
//         for (int x1 = 0; x1 < n; x1++)
//         {
//             for (int x2 = x1 + 1; x2 < n; x2++)
//             {
//                 if (not grid[x2][y] and dp[x1][y][max(x2 - 1, 0)][y])
//                 {
//                     dp[x1][y][x2][y] = true;
//                     ll curr_perimeter = 2 * ((1) + (x2 - x1 + 1));
//                     mx = max(mx, curr_perimeter);
//                 }
//             }
//         }
//     // considering each sub-matrix
//     rep(x1, n)
//     {
//         rep(y1, m)
//         {
//             for (int x2 = x1; x2 < n; x2++)
//             {
//                 for (int y2 = y1; y2 < m; y2++)
//                 {
//                     if (not grid[x2][y2] and dp[x1][y1][max(x2 - 1, 0)][y2] and dp[x1][y1][x2][max(y2 - 1, 0)])
//                     {
//                         dp[x1][y1][x2][y2] = true;
//                         ll curr_perimeter = 2 * ((x2 - x1 + 1) + (y2 - y1 + 1));
//                         mx = max(mx, curr_perimeter);
//                     }
//                 }
//             }
//         }
//     }
//     pr(mx);

//     return;
// }
// int32_t main()
// {
//     fastio;
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;
const int N = 30;

int n, m;
char s[N][N];

bool check(int x, int y, int u, int v)
{
    for (int i = x; i <= u; i++)
    {
        for (int j = y; j <= v; j++)
        {
            if (s[i][j] == '1')
                return false;
        }
    }
    return true;
}

ll perimeter(int x, int y, int u, int v)
{
    return 2 * (u - x + v - y + 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = i; k <= n; k++)
            {
                for (int l = j; l <= m; l++)
                {
                    if (check(i, j, k, l))
                    {
                        ans = max(ans, perimeter(i, j, k, l));
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}