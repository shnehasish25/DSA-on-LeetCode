/*
- ============================================================
- Problem   : Maximum Erasure Value
- LeetCode  : https://leetcode.com/problems/maximum-erasure-value/
- Problem # : 1695
- Difficulty: Medium
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Use an unordered_set to maintain a window of strictly unique elements, while keeping a running sum of the window.
- If a duplicate is encountered, shrink from the left (removing elements from the set and sum) until the duplicate is gone.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <unordered_set>

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> window;
        int max_score = 0, current_score = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while (window.count(nums[right])) {
                window.erase(nums[left]);
                current_score -= nums[left];
                left++;
            }
            
            window.insert(nums[right]);
            current_score += nums[right];
            
            max_score = max(max_score, current_score);
        }
        
        return max_score;
    }
};

/*
- Key Learnings:
- Mechanically identical to "Longest Substring Without Repeating Characters", but maximizing the 'sum' of elements rather than the 'length'.
- Shrinking the window dynamically using an unordered_set automatically clears up historical constraints.
 *
- Status: Accepted
 */