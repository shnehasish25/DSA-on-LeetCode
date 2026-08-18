/*
- ============================================================
- Problem   : Largest Rectangle in Histogram
- LeetCode  : https://leetcode.com/problems/largest-rectangle-in-histogram/
- Problem # : 84
- Difficulty: Hard
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Use a strictly Monotonic Increasing Stack storing indices.
- If we encounter a bar shorter than the stack top, it means the top bar's rectangle cannot extend further right. 
- Pop it, calculate its maximum possible area using the current index as the right boundary and the new stack top as the left boundary.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Treat the end of the array as a 0-height bar to flush the remaining stack
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && current_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, h * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};

/*
- Key Learnings:
- The width calculation is non-intuitive: (i - st.top() - 1). The popped bar can expand leftward all the way to the bar currently below it in the stack.
- Padding the array loop with an extra iteration (i == n, height 0) acts as a beautiful "flush" mechanism to force all pending rectangles in the stack to resolve.
 *
- Status: Accepted
 */