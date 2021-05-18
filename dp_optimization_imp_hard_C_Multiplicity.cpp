// dp[i][j] denotes using first i elements ,find the no of good subsequence of length j
// if(a[i] is divisible by j)
// dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
// else dp[i][j]=dp[i-1][j];


//space optimization

// as we need only 2 rows to calculate present state we can have dp[2][n] table and represent each index i as i%2


//Time and Space optimisation

//  In the final part, I used a 1D DP table to store dp[j] instead of dp[i][j] because the previous row of the 2D DP table was inefficiently being copied to the next row and hence only 1 row (i.e 1D) would suffice.

// Also , we had to observe that only divisors of a[i] were getting updated and we needed to update these divisors in decreasing order. Hence I extracted the divisors in the normal sqrt(a[i]) time to get a total time complexity of 10^5 * 10^3 = 10^8 operations.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    int n;
    cin>>n;
    vi a(n + 1);
    for (int i = 1;i<=n;i++)cin>>a[i];
    vi dp(1e6 + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2;i<=n;i++){
        //dp[i%2] = dp[(i + 1)%2];//replace the current row in the DP table with the previous row => takes O(n) time
        //Access j : a[i] is divisible
        //In other words we only need to update DP[i][j] for j being a divisor of a[i]

        vi toUpdate;

        for (int j = 1;j<=sqrt(a[i]);j++){
            if (a[i] % j == 0){
                toUpdate.pb(j);
                if (a[i] / j != j){
                    toUpdate.pb(a[i] / j);
                }
            }
        }
        //Need to be careful that we are updating DP[j] in the correct order

        sort(toUpdate.begin(),toUpdate.end());
        reverse(toUpdate.begin(),toUpdate.end());

        for (int j : toUpdate){//Updating DP[i][j] for j being a divisor of a[i]
            //cout<<j<<endl;
            dp[j] += dp[j - 1];//We are assuming that DP[j - 1] refers to the previous DP row which is not updated
            dp[j] %= mod;
            //DP[i][j] += DP[i - 1][j - 1]
        }//Transition time from 1 state to the other is O(sqrt(n)) time which is fine


    }

    int ans = 0;
    for (int i = 1;i<=n;i++)ans = (ans + dp[i])%mod;//sum of all dp[i] for i = 1 to N (consider all possible lengths of valid subsequences)
    cout<<ans;
    return 0;
}