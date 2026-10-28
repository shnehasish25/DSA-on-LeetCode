/*
- ============================================================
- Problem   : Remove Outermost Parentheses
- LeetCode  : https://leetcode.com/problems/remove-outermost-parentheses/
- Problem # : 1021
- Difficulty: Easy
- Topic     : String, Stack
 *
- Approach:
- Track the depth (or open count) of the parentheses.
- If depth is > 0 before evaluating '(', it belongs to the inner structure, so append it.
- If depth is > 1 before evaluating ')', it belongs to the inner structure, so append it.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n) for output string
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (open > 0) res += c;
                open++;
            } else {
                if (open > 1) res += c;
                open--;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The depth tracker tells you exactly which layer of nested primitives you are looking at. 
- Level 0 to 1 boundaries are strictly the "outermost" parentheses and are thus dropped.
 *
- Status: Accepted
 */