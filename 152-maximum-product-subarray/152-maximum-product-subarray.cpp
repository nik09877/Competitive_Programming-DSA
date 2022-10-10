class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(2));
        dp[0][0] = dp[0][1]=a[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0] = max({a[i]*dp[i-1][0],a[i]*dp[i-1][1],a[i]});
            dp[i][1] = min({a[i]*dp[i-1][0],a[i]*dp[i-1][1],a[i]});
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i][0]);
        return ans;
    }
};