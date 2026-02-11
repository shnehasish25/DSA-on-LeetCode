/*
- ============================================================
- Problem   : Find Pivot Index
- LeetCode  : https://leetcode.com/problems/find-pivot-index/
- Problem # : 724
- Difficulty: Easy
- Topic     : Array, Prefix Sum
 *
- Approach:
- Calculate the total sum of the array.
- Iterate through the array maintaining a running left sum. The right sum is exactly (total_sum - left_sum - nums[i]).
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;
        
        int left_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i];
        }
        
        return -1;
    }
};

/*
- Key Learnings:
- You don't always need to build a full prefix array in memory. A running variable often suffices.
- Total Sum math enables you to balance left/right equations instantly.
 *
- Status: Accepted
 */