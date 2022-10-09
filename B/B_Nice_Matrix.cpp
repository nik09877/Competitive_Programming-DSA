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
#define prl(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

///---------------Functions---------------------///
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int ceil(int numerator, int denominator)
{
    return (numerator + denominator - 1) / denominator;
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int cbrt(int x) //cuberoot
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
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

///---------------custom_hash---------------------///
class chash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    // umap<lli, lli, custom_hash> mp;
};

///---------------variables---------------------///
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int mod = 1000000007;

// Note, that if the value of a1,1 is equal to some number x, then values of an,1, a1,m and an,m must also be equal to this number x by the palindrome property.

// A similar property holds for all of the following elements ax,y (ax,y=an−x+1,y=a1,m−y+1=an−x+1,m−y+1), so the problem is reduced to finding the optimal number for each four of numbers (maybe less for some positions in matrix). This number is the median of these numbers (the average of the sorted set). The answer will be the sum of the differences between the median of the "four" and each number in the "four" for all "fours".
void solve()
{
    int n, m;
    lli ans = 0;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1));
    rep1(i, n)
    {
        rep1(j, m)
        {
            cin >> a[i][j];
        }
    }
    rep1(i, n / 2)
    {
        rep1(j, m / 2)
        {
            lli x = a[i][j];
            lli y = a[n - i + 1][j];
            lli z = a[i][m - j + 1];
            lli w = a[n - i + 1][m - j + 1];
            vector<lli> v = {x, y, z, w};
            sort(all(v));
            lli median = v[1];
            for (auto x : v)
            {
                ans += abs(median - x);
            }
        }
    }
    if ((n % 2) != 0)
    {
        int r = ceil(n, 2);
        rep1(j, m / 2)
        {
            lli x = a[r][j];
            lli y = a[r][m - j + 1];
            ans += 2 * max(x, y) - x - y; //median
        }
    }
    if (m % 2)
    {
        int c = ceil(m, 2);
        rep1(i, n / 2)
        {
            lli x = a[i][c];
            lli y = a[n - i + 1][c];
            ans += 2 * max(x, y) - x - y; //median
        }
    }
    prl(ans);
    // rep1(i, n)
    // {
    //     rep1(j, m)
    //     {
    //         cout << a[i][j] << sp;
    //     }
    //     cout << endl;
    // }
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