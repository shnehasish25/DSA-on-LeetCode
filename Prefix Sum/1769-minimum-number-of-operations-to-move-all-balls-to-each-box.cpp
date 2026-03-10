/*
- ============================================================
- Problem   : Minimum Number of Operations to Move All Balls to Each Box
- LeetCode  : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
- Problem # : 1769
- Difficulty: Medium
- Topic     : Array, String, Prefix Sum
 *
- Approach:
- Use two passes. First pass left-to-right: track accumulated balls and cumulative operations to move them to the current index.
- Second pass right-to-left: do the same for the right side and add it to the result array.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (excluding output array)
- ============================================================
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n, 0);
        
        int balls = 0, ops = 0;
        for (int i = 0; i < n; i++) {
            res[i] += ops;
            if (boxes[i] == '1') balls++;
            ops += balls;
        }
        
        balls = 0; ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += ops;
            if (boxes[i] == '1') balls++;
            ops += balls;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- A dynamic running sum (ops += balls) perfectly calculates movement cost without O(n^2) nested distance calculations.
- The dual-pass prefix summation isolates left-side dependencies from right-side dependencies cleanly.
 *
- Status: Accepted
 */