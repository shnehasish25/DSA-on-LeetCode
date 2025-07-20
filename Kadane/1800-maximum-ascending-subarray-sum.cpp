/*
- ============================================================
- Problem   : Maximum Ascending Subarray Sum
- LeetCode  : https://leetcode.com/problems/maximum-ascending-subarray-sum/
- Problem # : 1800
- Difficulty: Easy
- Topic     : Array, Dynamic Programming
 *
- Approach:
- Iterate through the array keeping a running sum.
- If the current number is strictly greater than the previous, add it. Otherwise, reset the sum to the current number.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current_sum += nums[i];
            } else {
                current_sum = nums[i];
            }
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};

/*
- Key Learnings:
- The core Kadane principle is "Reset when condition fails". Here, the condition is ascension instead of dropping below zero.
- Excellent warmup to recognize how Kadane's structure maps to sequence breaks.
 *
- Status: Accepted
 */