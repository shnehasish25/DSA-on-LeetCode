/*
- ============================================================
- Problem   : Populating Next Right Pointers in Each Node
- LeetCode  : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
- Problem # : 116
- Difficulty: Medium
- Topic     : Linked List, Tree, BFS
 *
- Approach:
- Since it's a perfect binary tree, we can use the already established 'next' pointers to traverse levels like a linked list.
- Connect 'node->left->next = node->right', and 'node->right->next = node->next->left'.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* leftmost = root;
        
        while (leftmost->left) {
            Node* curr = leftmost;
            while (curr) {
                // Connect children of the same parent
                curr->left->next = curr->right;
                
                // Connect right child to the left child of the next parent
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                
                curr = curr->next; // Move horizontally across the linked list
            }
            leftmost = leftmost->left; // Drop down to the next level
        }
        
        return root;
    }
};

/*
- Key Learnings:
- Treating tree levels as discrete Linked Lists entirely eliminates the need for a BFS Queue, dropping auxiliary space from O(N) to O(1).
- The parent level must be fully connected before the child level can use it to bridge gaps.
 *
- Status: Accepted
 */