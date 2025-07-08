/*
- ============================================================
- Problem   : Maximum Absolute Sum of Any Subarray
- LeetCode  : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
- Problem # : 1749
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- The absolute maximum is either the highest positive peak or the deepest negative valley.
- Run standard Kadane for both the maximum sum and the minimum sum, then return the max of their absolute values.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, curr_max = 0;
        int min_sum = 0, curr_min = 0;
        
        for (int num : nums) {
            curr_max = max(0, curr_max + num);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(0, curr_min + num);
            min_sum = min(min_sum, curr_min);
        }
        
        return max(max_sum, abs(min_sum));
    }
};

/*
- Key Learnings:
- Setting curr_max and curr_min to 0 bounds them, avoiding the need for an extra initialization variable.
- It proves that Kadane's algorithm is symmetrically powerful for finding both extremes of fluctuation.
 *
- Status: Accepted
 */