/*
- ============================================================
- Problem   : Reverse Substrings Between Each Pair of Parentheses
- LeetCode  : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
- Problem # : 1190
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Use a stack to track the exact index of the string whenever an open parenthesis '(' is encountered.
- When ')' is found, pop the start index and reverse the characters strictly between that index and the current end of the string.
- Finally, strip the parentheses out by building a clean string.
 *
- Time Complexity  : O(n^2) worst case, highly optimized string operations. (O(n) wormhole approach exists but is overkill for standard interviews).
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> st;
        string res = "";
        
        for (char c : s) {
            if (c == '(') {
                st.push_back(res.length());
            } else if (c == ')') {
                int start = st.back();
                st.pop_back();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Building the string dynamically and only pushing the lengths natively strips the '(' and ')' characters from the final evaluation without any cleanup loops.
- std::reverse operates directly on pointers/iterators, providing fast, localized mutation.
 *
- Status: Accepted
 */