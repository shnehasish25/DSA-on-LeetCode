/*
- ============================================================
- Problem   : Minimum Add to Make Parentheses Valid
- LeetCode  : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
- Problem # : 921
- Difficulty: Medium
- Topic     : String, Stack, Greedy
 *
- Approach:
- Track open unmatched '(' parentheses and unmatched closing ')' parentheses.
- On '(', increment open. On ')', if open > 0, decrement open (a pair is matched). If open == 0, increment unmatched_close.
- Total adds = unmatched_open + unmatched_close.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) open--;
                else close++;
            }
        }
        
        return open + close;
    }
};

/*
- Key Learnings:
- You don't need a physical Stack for single-bracket validation problems! Two integer counters achieve O(1) space.
- Greedy matching instantly guarantees the minimum number of insertions.
 *
- Status: Accepted
 */