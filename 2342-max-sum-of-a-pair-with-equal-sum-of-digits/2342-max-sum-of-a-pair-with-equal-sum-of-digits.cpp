class Solution {
public:
    int sod(int n){
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(auto x:nums){
            mp[sod(x)].push_back(x);
        }
        int ans=-1;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            if(it.second.size()>=2){
                ans=max(ans,it.second.back()+it.second[it.second.size()-2]);
            }
                
        }
        return ans;
    }
};