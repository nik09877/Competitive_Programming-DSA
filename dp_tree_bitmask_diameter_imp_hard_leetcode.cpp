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
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// int lcm(int a, int b)
// {
//     return (a * b) / __gcd(a, b);
// }
// int max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// int min(int a, int b)
// {
//     if (a < b)
//         return a;
//     else
//         return b;
// }
// int ceil(int numerator, int denominator)
// {
//     return (numerator + denominator - 1) / denominator;
// }
// bool isPrime(int N)
// {
//     for (int i = 2; i * i <= N; ++i)
//     {
//         if (N % i == 0)
//             return false;
//     }
//     return true;
// }
// int cbrt(int x) //cuberoot
// {
//     int lo = 1, hi = min(2000000ll, x);
//     while (hi - lo > 1)
//     {
//         int mid = (lo + hi) / 2;
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
// lli sqrt(lli target)
// {
//     lli l = 1, r = target;
//     while (r > l + 1)
//     {
//         lli m = (l + r) / 2;
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
//     int n = (int)a.size();
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

//1. iterate all the possible subtree from 1 to (1 << n - 1), the positions of 1 bits are the tree node ID.
//2. use dfs to calcuate the maximum distance for the subtree.
// 3.verfiy if the subtree is valid. once we visited a node then we clear the specific bit in the subtree, after finishing dfs, if subtree == 0, that means it is a valid subtree.
// 4.update ans by the maximum distance.

class Solution
{
public:
    unordered_set<int> g[16];
    int dfs(int u, int p, int &subtree, int &mx)
    {
        subtree = subtree ^ (1 << (u - 1)); //clear visited Node bit.
        int a = 0, b = 0;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if ((subtree & (1 << (v - 1))) == 0)
                continue; //the next node is not included in the subtree, ignore this node.
            int res = 1 + dfs(v, u, subtree, mx);
            if (res > a)
            {
                b = a;
                a = res;
            }
            else if (res > b)
            {
                b = res;
            }
        }
        mx = max(mx, a + b); //get the maximum distance in the subtree.
        return a;            //return the longest path from current node.
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n - 1);
        for (auto &e : edges)
        { //build graph.
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int size = 1 << n;
        for (int i = 1; i < size; ++i)
        {
            if ((i & (i - 1)) == 0) //power of 2
                continue;           //we don't need to calculate the subtree which have one node only.
            int subtree = i;
            int u = 0;
            int mx = 0;
            for (int j = 0; j < n; ++j)
            { // to get the start node.
                if ((1 << j) & i)
                {
                    u = j + 1;
                    break;
                }
            }
            int res = dfs(u, -1, subtree, mx);
            if (subtree == 0)
            {
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }
}