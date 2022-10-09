#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
#define M_PI 3.14159265358979323846

const int maxN = 2e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> dp(2e6 + 5);
// https://www.youtube.com/watch?v=_Ew_lr35TAo
void ok()
{
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i < maxN; i++)
    {
        long long ans = dp[i - 1] + 2LL * (dp[i - 2]) + (i % 3 == 0) * 4;
        ans %= MOD;
        dp[i] = ans;
    }
    return;
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] % MOD << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    ok();
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
