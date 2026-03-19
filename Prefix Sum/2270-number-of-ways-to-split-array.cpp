/*
- ============================================================
- Problem   : Number of Ways to Split Array
- LeetCode  : https://leetcode.com/problems/number-of-ways-to-split-array/
- Problem # : 2270
- Difficulty: Medium
- Topic     : Array, Prefix Sum
 *
- Approach:
- Find the total sum first. Iterate through the array up to n-1, maintaining a running left sum.
- The right sum is exactly (total_sum - left_sum). If left_sum >= right_sum, increment the count.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        for (int num : nums) total_sum += num;
        
        long long left_sum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            left_sum += nums[i];
            long long right_sum = total_sum - left_sum;
            
            if (left_sum >= right_sum) {
                count++;
            }
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Splitting problems strictly mandate iterating to n-1 because the right half must contain at least one element.
- Large constraints on elements necessitate tracking sums with 'long long' to avoid overflow on massive arrays.
 *
- Status: Accepted
 */