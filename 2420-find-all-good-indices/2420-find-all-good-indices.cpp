class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        vector<int>left(n),right(n);
        left[0] = right[n-1] = 1;
        for(int i=1;i<n;i++){
            left[i] = 1;
            if(nums[i]<=nums[i-1])
                left[i]+=left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = 1;
            if(nums[i]<=nums[i+1])
                right[i]+=right[i+1];
        }
        for(int i=k;i<n-k;i++){
            if(left[i-1]>=k and right[i+1]>=k)
                ans.push_back(i);
        }
        // for(auto x:left)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:right)
        //     cout<<x<<" ";
        // cout<<endl;
        return ans;
    }
};