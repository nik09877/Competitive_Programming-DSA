#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        ll ans = 0;
        int j=0,j_max=-1,j_min=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]<minK or a[i]>maxK)
            {
                j = i+1;
                j_min = j_max = -1;
                continue;
            }
            if(a[i]==minK)
                j_min=i;
            if(a[i]==maxK)
                j_max=i;
            ans+=max(0,min(j_min,j_max)-j+1);
        }
        return ans;
    }
};