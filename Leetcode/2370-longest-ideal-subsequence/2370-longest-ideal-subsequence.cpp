class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        for(int i=0;i<s.size();i++){
            int c1 = s[i]-'a';
            int dp_i = 1;
            for(int c2=0;c2<=25;c2++){
                if(abs(c1-c2)<=k){
                    dp_i = max(dp_i,1+dp[c2]);
                }
            }
            dp[c1] = dp_i;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};