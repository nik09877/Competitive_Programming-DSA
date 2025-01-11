import java.util.*;
//You are given two string arrays words1 and words2. 
//
// A string b is a subset of string a if every letter in b occurs in a 
//including multiplicity. 
//
// 
// For example, "wrr" is a subset of "warrior" but is not a subset of "world". 
// 
//
// A string a from words1 is universal if for every string b in words2, b is a 
//subset of a. 
//
// Return an array of all the universal strings in words1. You may return the 
//answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = [
//"e","o"]
//Output: ["facebook","google","leetcode"]
// 
//
// Example 2: 
//
// 
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = [
//"l","e"]
//Output: ["apple","google","leetcode"]
// 
//
// 
// Constraints: 
//
// 
// 1 <= words1.length, words2.length <= 10⁴ 
// 1 <= words1[i].length, words2[i].length <= 10 
// words1[i] and words2[i] consist only of lowercase English letters. 
// All the strings of words1 are unique. 
// 
//
// Related Topics Array Hash Table String 👍 3285 👎 290


//leetcode submit region begin(Prohibit modification and deletion)
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
//runtime:14 ms
//memory:54.6 MB

//leetcode submit region end(Prohibit modification and deletion)
