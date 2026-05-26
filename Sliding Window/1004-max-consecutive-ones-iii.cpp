/*
- ============================================================
- Problem   : Max Consecutive Ones III
- LeetCode  : https://leetcode.com/problems/max-consecutive-ones-iii/
- Problem # : 1004
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Expand the window. When you encounter a 0, decrement 'k'.
- If 'k' becomes negative, shrink the window from the left until a 0 is removed, thereby freeing up a 'k' flip.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, max_len = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) k--;
            
            while (k < 0) {
                if (nums[left] == 0) k++;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- Thinking of 'k' as a budget of zeroes you are allowed to absorb simplifies the logic.
- We don't modify the array to flip 0s to 1s; we just absorb them into our sliding window conditionally.
 *
- Status: Accepted
 */