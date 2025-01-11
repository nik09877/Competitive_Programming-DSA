class Solution {
public:
    // dp[i] denotes {length , value <= k} ending at i
    int longestSubsequence(string s, int k) {
        int val = 0, cnt = 0, pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
            if (s[i] == '1') {
            ++cnt;
            val += pow;
            }
            pow <<= 1;
        }
        return count(begin(s), end(s), '0') + cnt;
    }
};