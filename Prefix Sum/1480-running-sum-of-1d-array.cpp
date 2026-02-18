/*
- ============================================================
- Problem   : Running Sum of 1d Array
- LeetCode  : https://leetcode.com/problems/running-sum-of-1d-array/
- Problem # : 1480
- Difficulty: Easy
- Topic     : Array, Prefix Sum
 *
- Approach:
- Modify the array in place by adding the previous element's value to the current element.
- This creates a prefix sum array where each index stores the sum of all elements up to that point.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

/*
- Key Learnings:
- This is the fundamental building block of the Prefix Sum pattern.
- Overwriting the input array saves O(n) space if modifying the original data is allowed.
 *
- Status: Accepted
 */