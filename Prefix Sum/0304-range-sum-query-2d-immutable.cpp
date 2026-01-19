/*
- ============================================================
- Problem   : Range Sum Query 2D - Immutable
- LeetCode  : https://leetcode.com/problems/range-sum-query-2d-immutable/
- Problem # : 304
- Difficulty: Medium
- Topic     : Array, Design, Matrix, Prefix Sum
 *
- Approach:
- Build a 2D prefix sum array where prefix[i][j] stores the sum of the rectangle from (0,0) to (i-1,j-1).
- Calculate any sub-rectangle by taking the full area and subtracting the top/left areas, then adding back the overlapping top-left corner.
 *
- Time Complexity  : O(m * n) constructor, O(1) query
- Space Complexity : O(m * n)
- ============================================================
 */

#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
    }
};

/*
- Key Learnings:
- The Inclusion-Exclusion Principle is the core of 2D prefix sums: Area = Total - Top - Left + TopLeft (which got subtracted twice).
- Using a 1-indexed (padded with 0s) prefix matrix eliminates all out-of-bounds checks.
 *
- Status: Accepted
 */