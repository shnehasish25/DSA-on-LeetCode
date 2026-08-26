/*
- ============================================================
- Problem   : Maximal Rectangle
- LeetCode  : https://leetcode.com/problems/maximal-rectangle/
- Problem # : 85
- Difficulty: Hard
- Topic     : Array, Stack, Matrix, Monotonic Stack
 *
- Approach:
- Treat every row of the matrix as the base of a histogram (LeetCode 84).
- Maintain a running heights array. If the matrix cell is '1', increment the height; if '0', reset height to 0.
- Run the "Largest Rectangle in Histogram" monotonic stack algorithm on this array for every row.
 *
- Time Complexity  : O(rows * cols)
- Space Complexity : O(cols)
- ============================================================
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_rect = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            max_rect = max(max_rect, largestRectangleArea(heights));
        }
        
        return max_rect;
    }
};

/*
- Key Learnings:
- Complex 2D area problems can almost always be compressed into 1D array evaluations applied iteratively.
- Resetting the histogram pillar to 0 simulates the visual "floating" 1s not connecting to the floor.
 *
- Status: Accepted
 */