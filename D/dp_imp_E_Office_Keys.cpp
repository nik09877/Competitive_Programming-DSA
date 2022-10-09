#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x) cerr << #x << ": " << x << endl
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl

template <typename T>
T gcd(T a, T b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m)
{
    T ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans % m;
}

const int N = 2e3 + 5;

int n, k, p;
int a[N], b[N];
int cache[N][N];

//dp[i][j] =min(dp[i][j-1],max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
//dp[i][j] denotes minimum time for the i persons to reach destination using j keys
int dp(int i, int j)
{
    if (i == n + 1)
        return 0;
    if (j == k + 1)
        return 1e15;
    int &ans = cache[i][j];
    if (ans != -1)
        return ans;
    ans = min(dp(i, j + 1), max(abs(a[i] - b[j]) + abs(p - b[j]), dp(i + 1, j + 1)));
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    int ans = dp(1, 1);
    cout << ans;
    return 0;
}