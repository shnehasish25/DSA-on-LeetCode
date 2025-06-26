/*
- ============================================================
- Problem   : Maximum Product Subarray
- LeetCode  : https://leetcode.com/problems/maximum-product-subarray/
- Problem # : 152
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- A negative number can turn a tiny minimum product into a massive maximum product.
- Maintain both the current maximum and current minimum products ending at the current index. Swap them when a negative number is encountered.
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
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_prod = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if (num < 0) {
                swap(curr_max, curr_min);
            }
            
            curr_max = max(num, curr_max * num);
            curr_min = min(num, curr_min * num);
            
            max_prod = max(max_prod, curr_max);
        }
        
        return max_prod;
    }
};

/*
- Key Learnings:
- The Kadane pattern adapts to multiplication by carrying forward the absolute minimum (most negative) value.
- Resetting behavior naturally occurs via the max(num, curr * num) check, functioning just like current_sum < 0 in standard Kadane's.
 *
- Status: Accepted
 */