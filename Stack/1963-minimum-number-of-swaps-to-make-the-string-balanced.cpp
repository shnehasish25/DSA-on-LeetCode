/*
- ============================================================
- Problem   : Minimum Number of Swaps to Make the String Balanced
- LeetCode  : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
- Problem # : 1963
- Difficulty: Medium
- Topic     : String, Stack, Greedy, Two Pointers
 *
- Approach:
- Ignore valid pairs. Track the max number of unmatched closing brackets ']'.
- A single swap of an unmatched ']' with a future '[' fixes TWO errors simultaneously.
- Result is (max_imbalance + 1) / 2.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;
        int max_imbalance = 0;
        
        for (char c : s) {
            if (c == ']') {
                imbalance++;
            } else {
                imbalance--;
            }
            max_imbalance = max(max_imbalance, imbalance);
        }
        
        return (max_imbalance + 1) / 2;
    }
};

/*
- Key Learnings:
- A single swap always eliminates 2 unmatched closures because it moves a useful opening bracket to the front and pushes the closing bracket to the back.
- Math > Simulation.
 *
- Status: Accepted
 */