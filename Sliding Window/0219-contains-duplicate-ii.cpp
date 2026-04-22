/*
- ============================================================
- Problem   : Contains Duplicate II
- LeetCode  : https://leetcode.com/problems/contains-duplicate-ii/
- Problem # : 219
- Difficulty: Easy
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Use an unordered_set to represent a sliding window of maximum size 'k'.
- If the current element is in the set, a valid duplicate exists. Otherwise, add it.
- If the set size exceeds 'k', remove the oldest element (nums[i - k]).
 *
- Time Complexity  : O(n)
- Space Complexity : O(k)
- ============================================================
 */

#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) {
                return true;
            }
            
            window.insert(nums[i]);
            
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

/*
- Key Learnings:
- A sliding window doesn't always have to be managed with a left/right pointer; a Hash Set capped at size 'k' implicitly models the window perfectly.
- This gives O(k) space instead of the O(n) space required by a full Hash Map tracking indices.
 *
- Status: Accepted
 */