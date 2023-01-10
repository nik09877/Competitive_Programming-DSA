#define ll long long
class Solution {
public:
    int dp[100002][4],n;
    vector<int>a,b;
    int go(int i,int state){
        if(i==n)
            return 0;
        
        int& ans = dp[i][state];
        if(ans!=-1)
            return ans;
        
        ans = 0;
        
        if(state==0){
            ans = a[i]+go(i+1,state);
            ans = max(ans,b[i]+go(i+1,1));
        }
        else if(state==1){
            ans = b[i]+go(i+1,state);
            ans = max(ans,a[i]+go(i+1,2));
        }
        else if(state==2){
            ans = a[i]+go(i+1,state);
        }
        return ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        a = nums1,b=nums2;
        n = a.size();
        memset(dp,-1,sizeof(dp));

        int mx1 = go(0,0);
        
        swap(a,b);
        memset(dp,-1,sizeof(dp));
        int mx2 = go(0,0);
        
        return max(mx1,mx2);
    }
};