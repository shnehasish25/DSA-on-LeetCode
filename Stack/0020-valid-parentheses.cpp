/*
- ============================================================
- Problem   : Valid Parentheses
- LeetCode  : https://leetcode.com/problems/valid-parentheses/
- Problem # : 20
- Difficulty: Easy
- Topic     : String, Stack
 *
- Approach:
- Use a stack to keep track of opening brackets.
- When encountering a closing bracket, check if the stack is empty or if the top of the stack is not the corresponding opening bracket.
- If it matches, pop the opening bracket. At the end, the stack must be empty.
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
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

/*
- Key Learnings:
- The quintessential Stack problem. Stacks naturally resolve LIFO (Last-In-First-Out) dependencies, which is exactly how nested brackets work.
- Always check if the stack is empty *before* calling st.top() to avoid segmentation faults.
 *
- Status: Accepted
 */