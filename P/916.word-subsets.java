package P;

import java.util.*;
/*
 * @lc app=leetcode id=916 lang=java
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> result = new ArrayList<>();
        int charCntReq[] = new int[26];
        for (String word : words2) {
            int[] charCnt = new int[26];
            for (char ch : word.toCharArray()) {
                charCnt[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                charCntReq[i] = Math.max(charCntReq[i], charCnt[i]);
            }
        }
        for (String word : words1) {
            int[] charCnt = new int[26];
            for (char ch : word.toCharArray()) {
                charCnt[ch - 'a']++;
            }
            boolean universal = true;
            for (int i = 0; i < 26; i++) {
                if (charCnt[i] < charCntReq[i]) {
                    universal = false;
                }
            }
            if (universal) {
                result.add(word);
            }
        }
        return result;
    }

}
// @lc code=end
