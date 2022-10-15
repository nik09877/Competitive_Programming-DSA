#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        ll sum=0,ans=0;
        int n = a.size(),l=0;
        for(int r=0;r<n;r++){
            sum+=a[r];
            while(sum*(r-l+1) >= k){
                sum-=a[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};