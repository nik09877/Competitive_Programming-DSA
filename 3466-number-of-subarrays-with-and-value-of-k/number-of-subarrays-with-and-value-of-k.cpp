class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        /*
        if(a[i]&k == k)
            dp[i] = d[i-1]+1

        pos[ith bit].push_back(j) where 0<=j<n and 0<=i<32

        ans[i] = answer ending at i
        for each bit check how far up can we extend ,i.e last position of 0

        lb = i - dp[i] + 1
        ub = in range[lb,i] last position of 0th bit
        ans[i] = ub - lb + 1;
        */
        int n = a.size();
        vector<int>dp(n,0);
        vector<vector<int>>pos(32);
        long long ans = 0;

        for(int i=0;i<n;i++){
            if((a[i]&k) == k)
                dp[i] = 1 + ((i-1) >= 0 ? dp[i-1] : 0);
        }

        for(int i=0;i<32;i++){
            for(int j = 0;j<n;j++){
                int x = a[j];
                if(!(x&(1<<i)))
                    pos[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
                continue;
            if(dp[i]==1 ){
                if(a[i]==k)
                    ans+=1;
                continue;
            }
            int lb = i-dp[i]+1;
            int ub = i;
            for(int j=0;j<32;j++){
                if(k& (1<<j))
                    continue;
                if(pos[j].empty()){
                    ub = -1;
                    break;
                }
                auto it = upper_bound(pos[j].begin(),pos[j].end(),i);
                if(it == pos[j].begin()){
                    ub = -1;
                    break;
                }
                it--;
                if(*it < lb){
                    ub = -1;
                    break;
                }
                ub = min(ub,*it);
            }
            if(ub == -1){
                if(a[i]==k)
                    ans+=1;
                continue;
            }
            ans+=ub-lb+1;
        }
        return ans;
    }
};