class Solution {
public:
    int n,dp[100005];
    vector<int>a;
    int go(int i){
        if(i==n)
            return 1;
        int& ans = dp[i];
        if(ans!=-1)
            return ans;
        ans = 0;
        
        if(i+1<n and a[i] == a[i+1])
            ans =(ans || go(i+2));
        if(i+2<n and a[i]==a[i+1] and a[i]==a[i+2])
            ans = (ans || go(i+3));
        if(i+2<n and a[i+1]>a[i] and a[i+1]==a[i]+1 and a[i+2]>a[i+1] and a[i+2]==a[i+1]+1)
            ans = (ans || go(i+3));
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        a = nums;
        n = a.size();
        memset(dp,-1,sizeof(dp));
        return go(0);
    }
};