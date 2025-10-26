/*
- ============================================================
- Problem   : Linked List in Binary Tree
- LeetCode  : https://leetcode.com/problems/linked-list-in-binary-tree/
- Problem # : 1367
- Difficulty: Medium
- Topic     : Linked List, Tree, Depth-First Search
 *
- Approach:
- Run a DFS to traverse the tree. At every node, initiate a helper DFS to check if a downward path matches the linked list.
- Return true if the helper function successfully reaches the end of the linked list (nullptr).
 *
- Time Complexity  : O(N * min(L, H)) where N=tree nodes, L=list length, H=tree height
- Space Complexity : O(H) for recursion stack
- ============================================================
 */

class Solution {
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true; // Reached end of list successfully
        if (!root) return false; // Reached end of tree without finishing list
        if (head->val != root->val) return false;
        
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

/*
- Key Learnings:
- This is a dual-recursion problem. The outer recursion visits every tree node, and the inner recursion verifies the linked list structure starting from that node.
- Since it only matches downward paths, it behaves exactly like string matching in a trie.
 *
- Status: Accepted
 */