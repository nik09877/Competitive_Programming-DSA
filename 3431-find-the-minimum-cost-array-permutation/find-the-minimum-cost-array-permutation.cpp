class Solution {
public:
//The permutation array is circular so the order doesn't matter
//so fix the first element as 0
    int go(int prev_val,int mask,vector<vector<int>>&dp,vector<int>& nums){
        if(__builtin_popcount(mask) == 0){
            return dp[prev_val][mask] = abs(prev_val - nums[0]); 
        }
        int& ans = dp[prev_val][mask];
        if(ans!=-1)
            return ans;
        
        ans = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(mask&(1<<i)){
                ans = min(ans,abs(prev_val-nums[i])+go(i,mask^(1<<i),dp,nums));
            }
        }
        return ans;
    }
    void find_ans(int prev_val,int mask,vector<vector<int>>& dp,vector<int>& nums,vector<int>& perm){
        if(__builtin_popcount(mask)==0){
            // perm.push_back(prev_val);
            return;
        }
        for(int i=1;i<nums.size();i++){
            if(!(mask&(1<<i)))
            continue;
            int actual_mn = dp[prev_val][mask];
            int cur_perm_mn = abs(prev_val - nums[i]) + dp[i][mask^(1<<i)];
            if(actual_mn == cur_perm_mn){
                perm.push_back(i);
                find_ans(i,mask^(1<<i),dp,nums,perm);
                break;
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        int mask = (1<<n)-1;
        vector<vector<int>>dp(n,vector<int>(mask+1,-1));
        mask^=(1<<0);
        go(0,mask,dp,nums);
        vector<int>perm;
        perm.push_back(0);
        find_ans(0,mask,dp,nums,perm);
        return perm;
    }
};