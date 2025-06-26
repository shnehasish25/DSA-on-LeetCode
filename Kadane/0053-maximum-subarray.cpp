/*
- ============================================================
- Problem   : Maximum Subarray
- LeetCode  : https://leetcode.com/problems/maximum-subarray/
- Problem # : 53
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- Use Kadane's Algorithm. Maintain a running sum (current_sum).
- If current_sum drops below zero, reset it to zero (or the current element), as a negative sum will only drag down future subarrays.
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
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = 0;
        
        for (int num : nums) {
            if (current_sum < 0) {
                current_sum = 0;
            }
            current_sum += num;
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};

/*
- Key Learnings:
- Kadane's Algorithm is the definitive O(n) pattern for contiguous subarray sums.
- "A negative running sum is a liability" — dropping it immediately guarantees the optimal start point for the next potential sequence.
 *
- Status: Accepted
 */