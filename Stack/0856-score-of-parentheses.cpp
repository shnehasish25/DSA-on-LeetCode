/*
- ============================================================
- Problem   : Score of Parentheses
- LeetCode  : https://leetcode.com/problems/score-of-parentheses/
- Problem # : 856
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Maintain a stack that holds the current score for each nesting level.
- On '(': Push 0 (representing a new inner core).
- On ')': Pop the top score. The new score to add to the layer above it is max(2 * inner_score, 1).
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
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // Base level score
        
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int inner_score = st.top();
                st.pop();
                
                int addition = (inner_score == 0) ? 1 : 2 * inner_score;
                st.top() += addition;
            }
        }
        
        return st.top();
    }
};

/*
- Key Learnings:
- The base level stack initialization (st.push(0)) prevents empty stack checks and naturally accumulates parallel string fragments (e.g. "()()").
- Every ')' structurally collapses the tree back upwards.
 *
- Status: Accepted
 */