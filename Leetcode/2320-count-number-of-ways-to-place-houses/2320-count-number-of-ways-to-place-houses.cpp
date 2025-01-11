class Solution {
public:
    int dp[20004],mod = 1000000007;
    int go(int i,int& n){
        if(i>=2*n+1)
            return 1;
        int& ans = dp[i];
        if(ans!=-1)
            return ans;
        ans = 0;
        
        ans = (ans + go(i+1,n))%mod;
        if(i+1==n+1)
            ans = (ans + go(i+1,n))%mod;
        else
            ans = (ans + go(i+2,n))%mod;
        return ans;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        return go(1,n);
    }
};