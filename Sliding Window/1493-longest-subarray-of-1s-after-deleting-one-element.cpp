/*
- ============================================================
- Problem   : Longest Subarray of 1's After Deleting One Element
- LeetCode  : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
- Problem # : 1493
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Maintain a sliding window that contains at most one '0'. 
- Expand the window. If the count of 0s exceeds 1, shrink from the left until a '0' is removed.
- The valid length is strictly (window size - 1) because we MUST delete one element.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zero_count = 0, max_len = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zero_count++;
            
            while (zero_count > 1) {
                if (nums[left] == 0) zero_count--;
                left++;
            }
            
            // right - left is the size of window minus the 1 mandated deletion
            max_len = max(max_len, right - left);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- This is mechanically identical to "Max Consecutive Ones III" (where k = 1), except we are forced to delete exactly one element.
- Instead of returning 'right - left + 1', returning 'right - left' natively handles the required deletion math.
 *
- Status: Accepted
 */