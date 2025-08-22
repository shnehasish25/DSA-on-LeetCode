/*
- ============================================================
- Problem   : Convert Binary Search Tree to Sorted Doubly Linked List (Premium)
- LeetCode  : https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
- Problem # : 426
- Difficulty: Medium
- Topic     : Linked List, Tree, DFS
 *
- Approach:
- Perform an in-order traversal of the BST to process nodes in ascending order.
- Maintain a 'prev' pointer. Wire 'prev->right' to 'curr' and 'curr->left' to 'prev' to build the doubly linked list.
- Keep track of the 'first' node to eventually link it with the 'last' node to make it circular.
 *
- Time Complexity  : O(n)
- Space Complexity : O(h) for recursion stack
- ============================================================
 */

class Solution {
    Node* first = nullptr;
    Node* last = nullptr;
    
    void inorder(Node* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (last) {
            last->right = node;
            node->left = last;
        } else {
            first = node; // First node processed is the smallest
        }
        last = node;
        
        inorder(node->right);
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        
        inorder(root);
        
        // Close the circular doubly linked list
        last->right = first;
        first->left = last;
        
        return first;
    }
};

/*
- Key Learnings:
- In-order traversal naturally flattens a BST into a sorted sequence. 
- Using a global/class-level 'last' pointer perfectly tracks the tail of the expanding doubly linked list during recursion.
 *
- Status: Accepted
 */