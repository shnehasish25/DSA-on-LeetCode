/*
- ============================================================
- Problem   : Matrix Block Sum
- LeetCode  : https://leetcode.com/problems/matrix-block-sum/
- Problem # : 1314
- Difficulty: Medium
- Topic     : Array, Matrix, Prefix Sum
 *
- Approach:
- Build a 2D Prefix Sum array exactly like "Range Sum Query 2D".
- For every cell, calculate its bounding box coordinates (r-k, c-k) to (r+k, c+k), bounding it safely to 0 and size-1.
- Query the prefix map using the calculated box.
 *
- Time Complexity  : O(m * n)
- Space Complexity : O(m * n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k);
                
                // Offset by +1 for the 1-indexed prefix map
                r1++; c1++; r2++; c2++;
                
                res[i][j] = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            }
        }
        return res;
    }
};

/*
- Key Learnings:
- This is purely applying LeetCode #304 repeatedly across all cells.
- Using min() and max() is the cleanest way to prevent the bounding box (i - k, i + k) from spilling out of the matrix dimensions.
 *
- Status: Accepted
 */