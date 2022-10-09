#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    int target = n * (n + 1) / 2;
    if (target % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    target /= 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0)
            {
                (dp[i][j] += dp[i - 1][left]) %= mod;
            }
        }
    }
    // As we have double counted each set ex [{1,2,3},{4,5,6}] [{4,5,6},{1,2,3}] as two diff ways , but they are one
    //(we cant do ans = dp[n][target]/2 as modulo is involved)
    // so do ans = dp[n][target] * mod_inverse(2,mod);

    cout << (dp[n][target] * 1ll * 500000004) % mod << endl;

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= target; j++)
    //     {
    //         dp[i][j] = dp[i - 1][j];
    //         int left = j - i;
    //         if (left >= 0)
    //         {
    //             (dp[i][j] += dp[i - 1][left]) %= mod;
    //         }
    //     }
    // }
    // cout << dp[n - 1][target] << endl;
}