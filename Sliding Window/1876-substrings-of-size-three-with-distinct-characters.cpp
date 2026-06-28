/*
- ============================================================
- Problem   : Substrings of Size Three with Distinct Characters
- LeetCode  : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
- Problem # : 1876
- Difficulty: Easy
- Topic     : String, Sliding Window
 *
- Approach:
- Since the window size is strictly 3, we don't need a loop or map for frequency counting.
- Simply slide character by character and check if s[i], s[i-1], and s[i-2] are all distinct.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3) return 0;
        
        int count = 0;
        for (int i = 2; i < s.length(); i++) {
            if (s[i] != s[i-1] && s[i] != s[i-2] && s[i-1] != s[i-2]) {
                count++;
            }
        }
        return count;
    }
};

/*
- Key Learnings:
- Don't overengineer. If the window size is a tiny, fixed constant (like 3), direct if-condition comparisons are vastly faster than tracking a Hash Set.
- Always check string bounds at the start to avoid out-of-range errors on small inputs.
 *
- Status: Accepted
 */