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

class Solution
{
public:
    int n, sum;
    vector<vector<bool>> dp;
    vector<vector<int>> vis;
    vector<int> a;

    //EDITORIAL

    // so to avoid MLE we do -> keep a visited array to check if we have gotten the sum_so_far using i elements before so we dont have to compute it again ,this is possible cuz we can get the same sum using different elements,this is done using bitmasking

    //dp[i][j] stores if it is possible to have same avg using i elements and one array's sum is j

    //vis[i][cur_sum & (1<<i)] denotes if we have gotten sum i elements before this or not

    bool getAns(int i, int sum_so_far, int ele_taken_so_far)
    {
        if (i == n)
        {
            //to avoid division by 0 error
            if (ele_taken_so_far > 0 && ele_taken_so_far < n && (float)sum_so_far / ele_taken_so_far == (float)(sum - sum_so_far) / (n - ele_taken_so_far))
                return true;

            else
                return false;
        }

        else if (vis[i][sum_so_far] & (1 << ele_taken_so_far))
            return dp[i][sum_so_far];

        else
        {
            vis[i][sum_so_far] |= (1 << ele_taken_so_far);
            return dp[i][sum_so_far] = dp[i][sum_so_far] || getAns(i + 1, sum_so_far + a[i], ele_taken_so_far + 1) || getAns(i + 1, sum_so_far, ele_taken_so_far);
        }
    }

    bool splitArraySameAverage(vector<int> &num)
    {
        n = num.size();
        sum = 0;
        a = num;
        sum = accumulate(a.begin(), a.end(), 0);

        dp.resize(n + 1, vector<bool>(sum + 4, false));
        vis.resize(n + 1, vector<int>(sum + 4, 0));

        bool ans = getAns(0, 0, 0);

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