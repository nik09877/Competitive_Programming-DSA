class Solution {
public:
    int dp[11][2][1024];
    
    int getAns(int idx, int tight, int mask, string &digits) {
        if(idx == digits.size()) 
            return mask != 0;
        
        if(dp[idx][tight][mask] != -1)
            return dp[idx][tight][mask];

        int k = tight ? (digits[idx] - '0') : 9;
        int ans = 0;
        
        for(int i = 0; i <= k; i++) {
            
            if(mask & (1 << i)) continue;    
            
            int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
            
            int nextTight = (tight && i == (digits[idx] - '0')) ? 1 : 0;
            ans += getAns(idx + 1, nextTight, newMask, digits);
        }
        
        return dp[idx][tight][mask] = ans;
    }
    
    int countSpecialNumbers(int n) {
        string digits = to_string(n);
        memset(dp, -1, sizeof(dp));
        return getAns(0, 1, 0, digits);
    }
};