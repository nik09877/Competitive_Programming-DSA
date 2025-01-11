/*
 * @lc app=leetcode id=1400 lang=java
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
class Solution {
    public boolean canConstruct(String s, int k) {
        if (s.length() < k)
            return false;
        int[] cnt = new int[26];
        for (char ch : s.toCharArray()) {
            cnt[ch - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++)
            if ((cnt[i] & 1) != 0)
                odd++;
        return odd <= k;
    }
}
// @lc code=end
