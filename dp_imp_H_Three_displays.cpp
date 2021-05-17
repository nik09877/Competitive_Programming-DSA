#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define pr(x) cout << x
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 3005;
int n;
int cost[N];
int s[N];
int dp[N][N][5];

int getAns(int i, int prev, int total)
{
    if (total == 4)
        return 0;
    if (i == n + 1)
        return 3e8 + 1;

    int &ans = dp[i][prev][total];
    if (ans != -1)
        return ans;

    ans = getAns(i + 1, prev, total);
    if (s[i] > s[prev])
    {
        ans = min(ans, cost[i] + getAns(i + 1, i, total + 1));
    }
    return ans;
}
int32_t main()
{
    fastio;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    rep1(i, n) cin >> s[i];
    rep1(i, n) cin >> cost[i];

    int ans = getAns(1, 0, 1);
    if (ans > 3e8)
        ans = -1;
    pr(ans);
}