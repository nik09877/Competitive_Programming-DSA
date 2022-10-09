#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
const int mod = 1e9 + 7;
// dp[i][j] denotes no of ways to get a valid python program using i to n characters and indentation from j to n+1 as indentation of n lines can be at max n+1 
int main()
{
    int n;
    cin>>n;
    vc a(n + 1);
    for (int i = 1;i<=n;i++)cin>>a[i];
    vvi dp(n + 1,vi(n + 2));

    for (int l = 0;l<=n + 1;l++)dp[n][l] = 1;

    for (int i = n - 1;i>=1;i--){
        int sum = 0;
        for (int l = 0;l<=n;l++){

            sum += dp[i + 1][l];
            //sum stores dp[i + 1][l] + dp[i + 1][l - 1] + dp[i + 1][l - 2] + ... + dp[i + 1][0]
            //prefix sum 
            sum %= mod;

            if (a[i] == 'f'){
                dp[i][l] = dp[i + 1][l + 1];
            }
            else{
                dp[i][l] = sum;
            }
        }
    }

    cout<<dp[1][0];
    return 0;
}