/*
- ============================================================
- Problem   : Spiral Matrix IV
- LeetCode  : https://leetcode.com/problems/spiral-matrix-iv/
- Problem # : 2326
- Difficulty: Medium
- Topic     : Linked List, Array, Matrix, Simulation
 *
- Approach:
- Create an m x n matrix initialized to -1.
- Establish boundaries (top, bottom, left, right). Traverse the linked list, filling in the matrix while spiraling inward.
- Shrink the respective boundary every time a row or column is completed.
 *
- Time Complexity  : O(m * n)
- Space Complexity : O(m * n) for the output matrix
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (head) {
            // Left to Right
            for (int i = left; i <= right && head; i++) {
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;
            
            // Top to Bottom
            for (int i = top; i <= bottom && head; i++) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            // Right to Left
            for (int i = right; i >= left && head; i--) {
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            
            // Bottom to Top
            for (int i = bottom; i >= top && head; i--) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        
        return matrix;
    }
};

/*
- Key Learnings:
- Matrix boundary shrinking (top++, bottom--, etc.) seamlessly maps 1D structures into complex 2D patterns.
- Adding the "&& head" condition inside the inner loops guarantees we stop instantly when the linked list is exhausted.
 *
- Status: Accepted
 */