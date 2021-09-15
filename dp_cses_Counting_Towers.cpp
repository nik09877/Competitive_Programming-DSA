#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

// const int N = 1e6 + 5;
// int dp[N][2];

//dp[i][0] means no of ways of building tower of height i+1 if current row contains two bricks of width one
//dp[i][1] means no of ways of building tower of height i+1 if current row contains one brick of width two

// int32_t main()
// {
//     fast_io;
//     memset(dp, 0, sizeof(dp));
//     int n = 1e6;

//     //base case (if there is only one row to build)
//     dp[0][0] = dp[0][1] = 1;

//     for (int i = 1; i < n; i++)
//     {
//         //if I choose the current row brick to be of width 2 ,it can only happen if:

//         int op1 = (dp[i - 1][1] + dp[i - 1][0]) % mod; //dont want to extend from previous row
//         int op2 = (dp[i - 1][1]);                      //want to extend the brick's height present at i-1 th row ,but it can happen if ith row has brick of width 2
//         int op3 = (dp[i - 1][0] + dp[i - 1][0]) % mod; //want to extend left part or right part brick of i-1 th row and it can only happen if the ith row has bricks of width 1
//         int op4 = (dp[i - 1][0]);                      //want to extend both the left and right part brick of i-1 th row

//         //here 1 is multiplied to show that choosing to make the current row brick to have width 1 or 2 can be done in 1 way
//         dp[i][1] = ((1 * op1) % mod + (1 * op2) % mod) % mod;
//         dp[i][0] = ((1 * op1) % mod + (1 * op3) % mod + (1 * op4) % mod) % mod;
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         cin >> n;
//         cout << (dp[n - 1][0] % mod + dp[n - 1][1] % mod) % mod << endl;
//     }
//     return 0;
// }

int n = 1000000;
ll dp[1000001][2];
// dp[i][0]=number of ways to reach n th height if i th pos had 2 tiles of width 1

//dp[i][1]=if i th pos had a tile of width 2
int main()
{
    fast_io;
    int t = 1; //cin >> t;
    while (t--)
    {
        dp[n][0] = dp[n][1] = 1; //if there is only one row left

        for (int i = n - 1; i >= 1; i--)
        {
            ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % mod; //dont want to extend
            ll op2 = dp[i + 1][0];                        // extend both left and right brick
            ll op3 = (2 * dp[i + 1][0]) % mod;            // extend left or right brick but not both
            ll op4 = dp[i + 1][1];                        //extend whole brick of width 2

            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;
        }

        int q;
        cin >> q;
        while (q--)
        {
            int query;
            cin >> query;
            cout << (dp[1000000 - query + 1][1] + dp[1000000 - query + 1][0]) % mod << '\n';
        }
    }
    return 0;
}