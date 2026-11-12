/*
- ============================================================
- Problem   : Is Subsequence
- LeetCode  : https://leetcode.com/problems/is-subsequence/
- Problem # : 392
- Difficulty: Easy
- Topic     : Two Pointers, String
 *
- Approach:
- Maintain a pointer for string 's' and a pointer for string 't'.
- Iterate through 't', incrementing the 's' pointer only when characters match. If 's' reaches its end, it's a subsequence.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p_s = 0, p_t = 0;
        while (p_t < t.length() && p_s < s.length()) {
            if (s[p_s] == t[p_t]) {
                p_s++;
            }
            p_t++;
        }
        return p_s == s.length();
    }
};

/*
- Key Learnings:
- The relative order is inherently preserved simply by moving forward through string 't' and only confirming matches one by one.
- One of the purest, most straightforward applications of two pointers on different sized arrays.
 *
- Status: Accepted
 */