// #include <array>
// #include <cassert>
// #include <cmath>
// #include <iostream>
// using namespace std;
// //!EDITORIAL
// // There is a binary search method to solve this problem. We binary search for the minimum height required. Given a height h — how to check if it can fit all rectangles?

// // We first preprocess the given array to construct a new array ci = number of rectangles of width 1«i. The size of this array is < 20.

// // We iterate from largest width to smallest width. Let its width is wi. Then, we know that it fits only W/wi times in one layer. Therefore, with height h, the box can only fit in fi=h×(W/wi). So, we can say that if fi<ci, then this height is insufficient.

// // Therefore, we now know that for any i, if fi<ci, then the height is insufficient. Do we need more conditions to provably state that the given height is sufficient?

// // Yes! We also need to check if we can fit in the i-th block in combination with tthe i+1-th block. That is, when checking if the i-th block has enough space, we need to account for the space that has already been used by the i+1-th block. So, we need to update ci=ci+2×ci+1+4×ci+2….

// // Therefore, we only need to compute the suffix sum ci like so and then check the above conditions. Complexity is O(n+log(wmax)log(n)).

// #define PW 20
// array<int, PW> arr;
// int n, w;

// bool valid(int height)
// {
//     for (int pw = 0; pw < PW; pw++)
//     {
//         long long units_i_have = 1ll * height * (w / (1 << pw));
//         if (units_i_have < arr[pw])
//             return false;
//     }

//     return true;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         cin >> n >> w;

//         for (int i = 0; i < PW; i++)
//             arr[i] = 0;

//         for (int _ = 0; _ < n; _++)
//         {
//             int w;
//             cin >> w;
//             arr[log2(w)] += 1;
//         }

//         // suffix cumulative count
//         for (int i = PW - 2; i >= 0; i--)
//             arr[i] += 2 * arr[i + 1];

//         int beg = 1, end = n, ans = -1;
//         while (beg <= end)
//         {
//             int mid = (beg + end) / 2;

//             if (valid(mid))
//             {
//                 end = mid - 1;
//                 ans = mid;
//             }
//             else
//             {
//                 beg = mid + 1;
//             }
//         }

//         assert(ans != -1);
//         cout << ans << endl;
//     }
// }

//!Solution with multiset

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

// ///---------------Functions---------------------///
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
// ///---------------custom_hash---------------------///
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

// ///---------------variables---------------------///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int mod = 1000000007;

void solve()
{
    int n, W;
    cin >> n >> W;
    multiset<int> s;
    rep(i, n)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int height = 1, space_left = W;
    while (s.size())
    {
        auto it = s.upper_bound(space_left);
        if (it != s.begin())
        {
            it--;
            int val = *it;
            space_left -= val;
            s.erase(it);
        }
        else
        {
            space_left = W;
            height++;
        }
    }
    prln(height);
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
