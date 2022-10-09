#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define pr(x) cout << x
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

/**
 *dp[i][j] denotes the minimum cost ending at i and we have choosen j+1 elements

void solve()
{
    int n;
    cin >> n;
    vi s(n), cost(n);
    re(s, n);
    re(cost, n);
    int dp[n][3];
    rep(i, n) rep(j, 3) dp[i][j] = 3e8 + 5;
    rep(i, n) dp[i][0] = cost[i];
    rep(i, n)
    {
        rep(j, i)
        {
            if (s[j] < s[i])
            {
                dp[i][1] = min(dp[i][1], cost[i] + dp[j][0]);
                dp[i][2] = min(dp[i][2], cost[i] + dp[j][1]);
            }
        }
    }
    int ans = 3e8 + 5;
    rep(i, n) ans = min(ans, dp[i][2]);
    if (ans >= 3e8 + 5)
        prln(-1);
    else
        prln(ans);
    return;
}
*/

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