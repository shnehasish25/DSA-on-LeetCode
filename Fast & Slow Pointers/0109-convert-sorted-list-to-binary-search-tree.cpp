/*
- ============================================================
- Problem   : Convert Sorted List to Binary Search Tree
- LeetCode  : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
- Problem # : 109
- Difficulty: Medium
- Topic     : Linked List, Two Pointers, Divide and Conquer
 *
- Approach:
- Find the middle element using fast/slow pointers to act as the root of the BST to ensure height balance.
- Recursively build the left subtree from the left half and the right subtree from the right half.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(log n) (recursion stack)
- ============================================================
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev != nullptr) prev->next = nullptr;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};

/*
- Key Learnings:
- The middle of a sorted array/list perfectly bisects elements into BST subtrees. 
- Disconnecting the list at the 'prev' node prevents infinite recursion loops on the left half.
 *
- Status: Accepted
 */