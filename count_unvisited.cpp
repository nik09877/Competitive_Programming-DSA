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
public:
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

int n, m, x;
int dp[25001];
unordered_set<int> s;
int getAns(int pos)
{
    if (pos <= 0)
        return 0;

    if (dp[pos] != -1)
        return dp[pos];
    int a = 0;
    a = 1 + getAns(pos - n);

    int b = 0;
    b = 1 + getAns(pos - m);

    return dp[pos] = a + b;
}
void solve()
{
    cin >> n >> m;
    x = (m * n) - m - n;
    memset(dp, -1, sizeof(dp));
    int ans = getAns(x);
    prln(ans / 2);
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

string Reduced_String(long long k, string s)
{
    if (s.size() == 0)
        return "";

    stack<pair<char, long long>> stk;
    for (char c : s)
    {

        if (!stk.empty() && stk.top().second == k)
        {
            char cur = stk.top().first;
            while (!stk.empty() && stk.top().first == cur)
            {
                stk.pop();
            }
        }

        if (!stk.empty() && stk.top().first == c)
        {
            stk.push({c, stk.top().second + 1});
        }

        else
        {
            stk.push({c, 1});
        }
    }

    if (!stk.empty() && stk.top().second == k)
    {
        char cur = stk.top().first;
        while (!stk.empty() && stk.top().first == cur)
        {
            stk.pop();
        }
    }
    string ans;
    while (!stk.empty())
    {
        ans.push_back(stk.top().first);
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}