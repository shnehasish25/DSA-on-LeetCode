/*
- ============================================================
- Problem   : Minimum Value to Get Positive Step by Step Sum
- LeetCode  : https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
- Problem # : 1413
- Difficulty: Easy
- Topic     : Array, Prefix Sum
 *
- Approach:
- Keep a running prefix sum and track its absolute lowest drop.
- The start value must be just large enough to keep the sum strictly > 0 at that lowest point (i.e., absolute minimum drop + 1).
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
    int minStartValue(vector<int>& nums) {
        int min_prefix = 0;
        int current_sum = 0;
        
        for (int num : nums) {
            current_sum += num;
            min_prefix = min(min_prefix, current_sum);
        }
        
        return (min_prefix < 0) ? abs(min_prefix) + 1 : 1;
    }
};

/*
- Key Learnings:
- The worst-case drop defines the baseline constraint.
- If the running sum never dips below zero, the minimum required start value defaults to 1.
 *
- Status: Accepted
 */