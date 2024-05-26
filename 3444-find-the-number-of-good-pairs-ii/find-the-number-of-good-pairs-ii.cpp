#define ll long long
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll cnt=0;
        unordered_map<ll, ll> res;
        for(int x:nums2)res[x*k]++;
        for(int x:nums1){
            for(int i=1; i<=sqrt(x); i++) {
                if(x%i==0) {
                    int ans=x/i;
                    if(res.count(i)) cnt+=res[i];        
                    if(ans!=i && res.count(ans)) cnt+=res[ans];
                }
            }
        }
        return cnt;
    }
};