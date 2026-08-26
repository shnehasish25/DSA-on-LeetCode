/*
- ============================================================
- Problem   : Evaluate Reverse Polish Notation
- LeetCode  : https://leetcode.com/problems/evaluate-reverse-polish-notation/
- Problem # : 150
- Difficulty: Medium
- Topic     : Array, Math, Stack
 *
- Approach:
- Iterate through the tokens. If a token is a number, push it onto the stack.
- If it's an operator, pop the top two numbers, apply the operator (careful with operand order: second popped is left operand), and push the result back.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; // Use long long to prevent overflow during intermediate calculations
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                st.push(stoll(token));
            }
        }
        
        return st.top();
    }
};

/*
- Key Learnings:
- Postfix notation (RPN) is inherently designed for Stack execution because operands immediately precede their operators.
- Order matters for division and subtraction: the *first* popped element is the *right* operand.
 *
- Status: Accepted
 */