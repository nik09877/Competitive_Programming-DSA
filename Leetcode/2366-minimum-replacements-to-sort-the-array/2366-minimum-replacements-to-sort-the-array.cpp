#define ll long long
class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        int mn = a.back(),n=a.size();
        long long ans=0;
        for(int i=n-2;i>=0;i--){
            if(a[i]<=mn){
                mn = a[i];
                continue;
            }
            ll cnt = a[i]/mn;
            ll rem = a[i]%mn;
            ll tot = cnt;
            if(rem)
                tot++;
            ll avg = (rem+mn*cnt)/tot;
            ans+=tot-1;
            mn=avg;
        }
        return ans;
    }
};