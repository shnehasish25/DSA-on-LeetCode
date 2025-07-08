/*
- ============================================================
- Problem   : Maximum Length of Subarray With Positive Product
- LeetCode  : https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
- Problem # : 1567
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- Track the current length of the positive product and the negative product.
- On a negative number, the positive and negative lengths swap. On a zero, both lengths reset.
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
    int getMaxLen(vector<int>& nums) {
        int pos_len = 0, neg_len = 0;
        int max_len = 0;
        
        for (int x : nums) {
            if (x == 0) {
                pos_len = 0;
                neg_len = 0;
            } else if (x > 0) {
                pos_len++;
                neg_len = (neg_len > 0) ? neg_len + 1 : 0;
            } else {
                int temp = pos_len;
                pos_len = (neg_len > 0) ? neg_len + 1 : 0;
                neg_len = temp + 1;
            }
            max_len = max(max_len, pos_len);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- Mechanically identical to Maximum Product Subarray, but instead of tracking the values, you track the lengths.
- Only increment neg_len on positive numbers if a negative sequence has already started (neg_len > 0).
 *
- Status: Accepted
 */