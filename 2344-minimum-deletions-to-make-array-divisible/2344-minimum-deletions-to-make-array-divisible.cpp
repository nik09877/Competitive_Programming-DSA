class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=0;
        for(auto x:numsDivide)
            g = __gcd(g,x);
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        
        for(int i=1;i*i<=g;i++)
        {
            if(g%i==0)
            {
                int temp_ans = lower_bound(nums.begin(),nums.end(),i)-nums.begin();
                if(temp_ans!=nums.size() and nums[temp_ans]==i)
                    ans=min(ans,temp_ans);
                if(i!=(g/i))
                {
                    temp_ans = lower_bound(nums.begin(),nums.end(),(g/i))-nums.begin();
                    if(temp_ans!=nums.size() and nums[temp_ans]==(g/i))
                        ans=min(ans,temp_ans);
                }
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};