/*
- ============================================================
- Problem   : Find the Pivot Integer
- LeetCode  : https://leetcode.com/problems/find-the-pivot-integer/
- Problem # : 2485
- Difficulty: Easy
- Topic     : Math, Prefix Sum
 *
- Approach:
- The sum from 1 to x must equal the sum from x to n.
- Sum(1 to n) is total_sum = n * (n + 1) / 2.
- We need x * (x + 1) / 2 == total_sum - x * (x - 1) / 2.
- Simplified: x^2 = total_sum. Therefore, x must be the integer square root of total_sum.
 *
- Time Complexity  : O(1)
- Space Complexity : O(1)
- ============================================================
 */

#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = n * (n + 1) / 2;
        int x = sqrt(total_sum);
        
        if (x * x == total_sum) {
            return x;
        }
        
        return -1;
    }
};

/*
- Key Learnings:
- Mathematical prefix sums (arithmetic progressions) can completely bypass loops.
- O(N) loop traversal is fine, but recognizing the algebraic simplification reduces the problem to O(1) time.
 *
- Status: Accepted
 */