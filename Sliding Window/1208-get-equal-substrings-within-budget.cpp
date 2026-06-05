/*
- ============================================================
- Problem   : Get Equal Substrings Within Budget
- LeetCode  : https://leetcode.com/problems/get-equal-substrings-within-budget/
- Problem # : 1208
- Difficulty: Medium
- Topic     : String, Sliding Window
 *
- Approach:
- Treat the problem as finding the longest contiguous subarray where the sum of costs (absolute difference of characters) is <= maxCost.
- Expand the right pointer, adding the cost. If cost exceeds budget, advance the left pointer and subtract its cost.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <cmath>

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, current_cost = 0, max_len = 0;
        
        for (int right = 0; right < s.length(); right++) {
            current_cost += abs(s[right] - t[right]);
            
            while (current_cost > maxCost) {
                current_cost -= abs(s[left] - t[left]);
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- This is a disguised "Maximum Subarray Sum less than or equal to K" problem.
- Transforming string transformations into an array of integer costs unlocks the standard sliding window budget template.
 *
- Status: Accepted
 */