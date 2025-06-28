/*
- ============================================================
- Problem   : Maximum Sum Circular Subarray
- LeetCode  : https://leetcode.com/problems/maximum-sum-circular-subarray/
- Problem # : 918
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- A circular max subarray is either standard Kadane's (in the middle) OR it wraps around the edges.
- Wrapping around equals (Total Sum - Minimum Subarray Sum). Run both Max Kadane and Min Kadane.
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_max = 0, max_sum = nums[0];
        int curr_min = 0, min_sum = nums[0];
        
        for (int num : nums) {
            total_sum += num;
            
            curr_max = max(curr_max + num, num);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(curr_min + num, num);
            min_sum = min(min_sum, curr_min);
        }
        
        // If all numbers are negative, max_sum will be the highest negative number.
        // Total sum - min_sum would be 0 (empty array), which is invalid.
        if (max_sum > 0) {
            return max(max_sum, total_sum - min_sum);
        }
        return max_sum;
    }
};

/*
- Key Learnings:
- Min Kadane is just as powerful as Max Kadane. Subtracting the worst contiguous part leaves the best wrapping parts.
- Always check the edge case where all numbers are negative to prevent returning an invalid empty array sum (0).
 *
- Status: Accepted
 */