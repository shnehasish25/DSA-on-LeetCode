/*
- ============================================================
- Problem   : Basic Calculator
- LeetCode  : https://leetcode.com/problems/basic-calculator/
- Problem # : 224
- Difficulty: Hard
- Topic     : Math, String, Stack
 *
- Approach:
- Only '+', '-', and parentheses are allowed.
- Maintain a running 'result' and a 'sign' (1 or -1).
- When seeing '(', push the current result and sign onto the stack, then reset them for the inner expression.
- When seeing ')', pop the sign, multiply it with the current result, and add it to the popped result.
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
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1;
        
        for (char c : s) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }
        if (number != 0) result += sign * number;
        return result;
    }
};

/*
- Key Learnings:
- The stack completely isolates sub-expressions. You stash the active state, compute the inner parentheses starting from scratch, and weave them back together upon exiting.
 *
- Status: Accepted
 */