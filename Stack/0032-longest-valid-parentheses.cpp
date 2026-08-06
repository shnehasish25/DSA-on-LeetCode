/*
- ============================================================
- Problem   : Longest Valid Parentheses
- LeetCode  : https://leetcode.com/problems/longest-valid-parentheses/
- Problem # : 32
- Difficulty: Hard
- Topic     : String, Stack
 *
- Approach:
- Use a stack to store the indices of the characters.
- Initialize the stack with -1 to act as a base for the first valid substring.
- On '(', push its index. On ')', pop the top. If the stack becomes empty, push the current index as the new base. If not empty, calculate length (i - st.top()).
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- Pushing -1 initially gives a continuous baseline to calculate lengths against, mimicking the mathematical bounds of a 0-indexed array.
- A stack storing *indices* instead of characters perfectly tracks both validation and substring length simultaneously.
 *
- Status: Accepted
 */