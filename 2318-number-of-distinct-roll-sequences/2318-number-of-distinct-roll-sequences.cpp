class Solution {
public:
    int dp[10001][7][7],n,mod = 1000000007;
    int go(int i,int pre1,int pre2){
        if(i==n)
            return 1;
        int& ans = dp[i][pre1][pre2];
        if(ans!=-1)
            return ans;
        ans = 0;
        for(int dice=1;dice<=6;dice++){
            if(dice==pre1 or dice==pre2 or __gcd(dice,pre1)!=1)
                continue;
            ans = (ans + go(i+1,dice,pre1))%mod;
        }
        return ans;
    }
    int distinctSequences(int x) {
        n=x;
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int dice = 1;dice <=6;dice++)
            ans= (ans + go(1,dice,0))%mod;
        return ans;
    }
};