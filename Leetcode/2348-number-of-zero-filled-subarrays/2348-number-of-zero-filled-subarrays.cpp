class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans=0, cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==0)
                cnt++;
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;

        return ans;
    }
};