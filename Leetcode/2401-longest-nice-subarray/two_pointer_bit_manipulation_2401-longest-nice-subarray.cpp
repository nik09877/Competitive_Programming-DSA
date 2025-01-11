class Solution {
public:
    void add(int x,vector<int>& cnt){
        for(int i=0;i<32;i++)
            if(x&(1<<i))
                cnt[i]++;
    }
    void remove(int x,vector<int>& cnt){
        for(int i=0;i<32;i++)
            if(x&(1<<i))
                cnt[i]--;
    }
    bool good(vector<int>& cnt){
        for(int i=0;i<32;i++)
            if(cnt[i]>1)
                return false;
        return true;
    }
    int longestNiceSubarray(vector<int>& a) {
        vector<int>cnt(32,0);
        int ans=0;
        int l=0;
        for(int r=0;r<a.size();r++){
            add(a[r],cnt);
            while(!good(cnt)){
                remove(a[l],cnt);
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};