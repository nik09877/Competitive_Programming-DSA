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
const int INF = 1000000007;

int n;
vi a;
lli dp[101][3][3];

int getAns(int idx, int prev_gym, int prev_contest)
{
    if (idx > n)
        return 0;

    if (dp[idx][prev_gym][prev_contest] != INF)
        return dp[idx][prev_gym][prev_contest];

    //a[idx]==3
    int A(INF), b(INF);
    if (prev_gym == 0 and prev_contest == 0 and a[idx] == 3)
    {
        A = getAns(idx + 1, 1, 0);
        b = getAns(idx + 1, 0, 1);
    }

    //take rest, a[idx]==0
    int x = INF;
    if (a[idx] == 0 || (prev_gym == 1 && a[idx] == 2) || (prev_contest == 1 && a[idx] == 1))
        x = 1 + getAns(idx + 1, 0, 0);

    //go to gym
    int y = INF;
    if (prev_gym != 1 and a[idx] != 0 and a[idx] != 1)
        y = getAns(idx + 1, 1, 0);

    //participate in contest
    int z = INF;
    if (prev_contest != 1 and a[idx] != 0 and a[idx] != 2)
        z = getAns(idx + 1, 0, 1);

    return dp[idx][prev_gym][prev_contest] = min({x, y, z, A, b});
}
void solve()
{
    cin >> n;

    a.resize(n + 1);

    rep1(i, n) cin >> a[i];

    rep1(i, n) rep(j, 2) rep(k, 2) dp[i][j][k] = INF;

    int ans = getAns(1, 0, 0);

    prl(ans);
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