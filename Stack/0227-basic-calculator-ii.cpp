/*
- ============================================================
- Problem   : Basic Calculator II
- LeetCode  : https://leetcode.com/problems/basic-calculator-ii/
- Problem # : 227
- Difficulty: Medium
- Topic     : Math, String, Stack
 *
- Approach:
- This variation has '+', '-', '*', '/' but NO parentheses.
- Use a stack to hold numbers waiting to be added.
- If operator is '+' or '-', push the number (or its negative). If '*' or '/', pop the top, perform the operation with the current number, and push back.
- Sum the stack at the end.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> st; // Vector acting as a stack
        int current_number = 0;
        char operation = '+';
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                current_number = current_number * 10 + (c - '0');
            }
            if (!isdigit(c) && !isspace(c) || i == s.length() - 1) {
                if (operation == '+') {
                    st.push_back(current_number);
                } else if (operation == '-') {
                    st.push_back(-current_number);
                } else if (operation == '*') {
                    st.back() *= current_number;
                } else if (operation == '/') {
                    st.back() /= current_number;
                }
                operation = c;
                current_number = 0;
            }
        }
        
        int result = 0;
        for (int num : st) result += num;
        return result;
    }
};

/*
- Key Learnings:
- Deferring addition and subtraction to the very end handles BEDMAS/PEMDAS order of operations flawlessly.
- Multiplication and division bind tightly, so they mutate the immediate stack top instantly.
 *
- Status: Accepted
 */