/*
- ============================================================
- Problem   : Count Submatrices With All Ones
- LeetCode  : https://leetcode.com/problems/count-submatrices-with-all-ones/
- Problem # : 1504
- Difficulty: Medium
- Topic     : Array, Dynamic Programming, Stack, Monotonic Stack
 *
- Approach:
- Treat every row as the base of a histogram (accumulate 1s vertically).
- For each row, use a monotonic increasing stack to compute the number of valid submatrices ending at each column.
- The contribution of a column is calculated by extending the submatrices from the nearest smaller column.
 *
- Time Complexity  : O(rows * cols)
- Space Complexity : O(cols)
- ============================================================
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int total_submatrices = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
            }
            
            stack<int> st;
            vector<int> sum(n, 0);
            
            for (int j = 0; j < n; j++) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                
                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + heights[j] * (j - prev);
                } else {
                    sum[j] = heights[j] * (j + 1);
                }
                
                total_submatrices += sum[j];
                st.push(j);
            }
        }
        
        return total_submatrices;
    }
};

/*
- Key Learnings:
- Extends "Maximal Rectangle" (LeetCode 85). Instead of max area, we use Dynamic Programming coupled with the Stack to count total overlapping rectangles.
- 'sum[j]' stores the number of valid submatrices strictly bottom-right anchored at (i, j).
 *
- Status: Accepted
 */