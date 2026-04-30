/*
- ============================================================
- Problem   : Subarray Product Less Than K
- LeetCode  : https://leetcode.com/problems/subarray-product-less-than-k/
- Problem # : 713
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Use a sliding window to maintain the product of elements.
- Expand by multiplying the right element. If the product >= k, shrink from the left by dividing until product < k.
- The number of valid subarrays ending at 'right' is exactly the size of the window (right - left + 1).
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int count = 0, left = 0;
        long long product = 1; // Prevent overflow
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            count += (right - left + 1);
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Counting subarrays in a sliding window is governed by a strict mathematical rule: adding a new element to a valid window of size N adds exactly N new valid subarrays.
- Always check the edge case (k <= 1) because all positive integers are >= 1, meaning the window would never be valid.
 *
- Status: Accepted
 */