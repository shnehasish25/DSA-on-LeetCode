/*
- ============================================================
- Problem   : Flatten Binary Tree to Linked List
- LeetCode  : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
- Problem # : 114
- Difficulty: Medium
- Topic     : Linked List, Stack, Tree, DFS
 *
- Approach:
- Use Morris Traversal concept for O(1) space. 
- If a node has a left child, find the rightmost node of the left subtree. Wire it to the current node's right child.
- Move the left subtree to the right, nullify the left pointer, and advance to the right.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* rightmost = curr->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                
                rightmost->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

/*
- Key Learnings:
- Restructuring binary trees into right-skewed linked lists in O(1) space is the definitive use-case for Morris Traversal logic.
- Wiring the rightmost node of the left subtree to the original right child preserves the exact pre-order structure.
 *
- Status: Accepted
 */