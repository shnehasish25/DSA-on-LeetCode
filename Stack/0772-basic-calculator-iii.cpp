/*
- ============================================================
- Problem   : Basic Calculator III (Premium)
- LeetCode  : https://leetcode.com/problems/basic-calculator-iii/
- Problem # : 772
- Difficulty: Hard
- Topic     : String, Stack, Math
 *
- Approach:
- Unifies Basic Calculator I & II. We have '+', '-', '*', '/', and parentheses.
- Recursively evaluate parenthesis blocks. Treat the result of a parenthesis block exactly like a parsed integer.
- Use a stack/vector for the current block to handle BEDMAS order of operations before summing.
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
    int parse(string& s, int& i) {
        vector<int> st;
        char op = '+';
        long long num = 0;
        
        while (i < s.length()) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '(') {
                i++;
                num = parse(s, i); // Recursively resolve inner scope
            }
            
            if (!isdigit(c) && c != ' ' && c != '(' || i == s.length() - 1) {
                if (op == '+') st.push_back(num);
                else if (op == '-') st.push_back(-num);
                else if (op == '*') st.back() *= num;
                else if (op == '/') st.back() /= num;
                
                op = c;
                num = 0;
            }
            
            if (c == ')') break; // Exit the current recursive scope
            i++;
        }
        
        int res = 0;
        for (int x : st) res += x;
        return res;
    }
    
public:
    int calculate(string s) {
        int i = 0;
        return parse(s, i);
    }
};

/*
- Key Learnings:
- Passing the index 'i' by reference recursively is vastly superior to using an explicit stack of stacks. It acts as a continuous string consumer.
- This is the ultimate, universal expression evaluator architecture.
 *
- Status: Accepted
 */