/*
- ============================================================
- Problem   : Number of Visible People in a Queue
- LeetCode  : https://leetcode.com/problems/number-of-visible-people-in-a-queue/
- Problem # : 1944
- Difficulty: Hard
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Traverse from right to left using a Monotonic Decreasing Stack.
- When processing a person, pop all shorter people from the stack. The person sees all of them (count++ for each pop).
- If the stack is not empty after popping, the person can also see the taller person who finally stopped them (count++).
- Push the current person to the stack.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> st; // Stores heights
        
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && heights[i] > st.top()) {
                st.pop();
                count++;
            }
            
            if (!st.empty()) {
                count++; // Can see the taller person that blocked the view
            }
            
            res[i] = count;
            st.push(heights[i]);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Iterating right-to-left is the standard template for "looking forward" problems.
- Visible people directly map to the elements you pop plus exactly one blocking element.
 *
- Status: Accepted
 */