class Solution {
public:
    int k,n,total;
    vector<int>a;
    int dp[8][(1<<8)-1];
    
    int go(int i,int mask){
        if(mask==total)
            return 0;
        if(i==k){
            if(mask==total)
                return 0;
            return INT_MAX;
        }
        int& ans = dp[i][mask];
        if(ans!=-1)
            return ans;
        
        ans = INT_MAX;
        for(int new_mask = mask;new_mask<=total;new_mask++){
            if((new_mask& mask) == mask){
                int cur_cookie_sum = 0;
                int extra_in_mask = new_mask^mask;
                for(int bit=0;bit<n;bit++)
                {
                    if(extra_in_mask &(1<<bit))
                        cur_cookie_sum+=a[bit];
                }
                int temp = max(cur_cookie_sum,go(i+1,new_mask));
                ans = min(ans,temp);
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& nums, int K) {
        memset(dp,-1,sizeof(dp));
        k=K;
        n=nums.size();
        a=nums;
        total = (1<<n)-1;
        return go(0,0);
    }
};