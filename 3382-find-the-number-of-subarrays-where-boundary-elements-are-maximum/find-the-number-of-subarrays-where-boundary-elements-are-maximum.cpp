class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n,1);
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 and nums[i] > nums[st.top()] )
                st.pop();
            if(st.size() > 0 and nums[i] == nums[st.top()]){
                dp[i]+=dp[st.top()];
            }
            st.push(i);
        }
        long long ans = accumulate(dp.begin(),dp.end(),0ll);
        return ans;
    }
};