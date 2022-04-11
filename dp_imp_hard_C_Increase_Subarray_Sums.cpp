/**
 *    author  : Nikhil Kumar Mishra
 *    created : 22.02.2022 20:53:10
 **/
#include "bits/stdc++.h"
using namespace std;

template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}
// dp[i][k] denotes maximum answer ending at i such that we can increase k elements by x
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int tt = -1; tt < 0 && cin >> tt, tt--;)
        [&]()
        {
            int64_t n, x;
            cin >> n >> x;
            vector<int64_t> a(n + 1);
            vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1, 0));
            for (int i = 1; i <= n; ++i)
            {
                cin >> a[i];
            }
            for (int i = 1; i <= n; ++i)
            {
                dp[i][0] = max({0LL, dp[i - 1][0] + a[i], a[i]});
                for (int k = 1; k <= n; k++)
                {
                    dp[i][k] = max({dp[i - 1][k] + a[i], dp[i - 1][k - 1] + a[i] + x, 0LL});
                }
            }
            for (int j = 0; j <= n; ++j)
            {
                int64_t ans = 0;
                for (int i = 1; i <= n; i++)
                {
                    ckmax(ans, dp[i][j]);
                }
                cout << ans << " ";
            }
            cout << endl;
            return 0;
        }();
    return 0;
}
