/*
- ============================================================
- Problem   : Minimum Remove to Make Valid Parentheses
- LeetCode  : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
- Problem # : 1249
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Use a stack to track the indices of unmatched '(' parentheses.
- If a ')' is found and the stack is empty, it's invalid—mark it in the string (e.g., with '*'). If valid, pop the stack.
- Finally, iterate through the string and strip out the '*' markers, as well as any unmatched '(' left in the stack.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    s[i] = '*'; // Mark invalid closing
                } else {
                    st.pop();
                }
            }
        }
        
        // Mark invalid opening (unmatched)
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        string res = "";
        for (char c : s) {
            if (c != '*') res += c;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The stack's leftover contents after the string traversal literally map to the "unmatched" errors.
- Masking strings in-place with a dummy character like '*' is faster than trying to slice strings dynamically.
 *
- Status: Accepted
 */