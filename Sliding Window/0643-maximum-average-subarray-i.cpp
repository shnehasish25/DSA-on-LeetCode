/*
- ============================================================
- Problem   : Maximum Average Subarray I
- LeetCode  : https://leetcode.com/problems/maximum-average-subarray-i/
- Problem # : 643
- Difficulty: Easy
- Topic     : Array, Sliding Window
 *
- Approach:
- Calculate the sum of the first 'k' elements.
- Slide the window of size 'k' by adding the new element and subtracting the oldest element. Track the maximum sum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        for (int i = k; i < nums.size(); i++) {
            current_sum += nums[i] - nums[i - k];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        return max_sum / k;
    }
};

/*
- Key Learnings:
- The most basic implementation of a fixed-size sliding window.
- Calculate the average at the very end to prevent floating-point inaccuracies and division overhead during the loop.
 *
- Status: Accepted
 */