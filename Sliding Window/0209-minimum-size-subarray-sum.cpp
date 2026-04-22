/*
- ============================================================
- Problem   : Minimum Size Subarray Sum
- LeetCode  : https://leetcode.com/problems/minimum-size-subarray-sum/
- Problem # : 209
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Add elements to a running sum by moving the right pointer.
- When the sum >= target, record the window size and subtract from the left pointer, moving it forward to find a potentially smaller valid window.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, current_sum = 0, min_len = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        
        return min_len == INT_MAX ? 0 : min_len;
    }
};

/*
- Key Learnings:
- This is the most fundamental dynamic sliding window problem. The window acts like a caterpillar, stretching to meet the condition and shrinking to optimize it.
- Initialize minimums to INT_MAX and check at the end if they were never updated.
 *
- Status: Accepted
 */