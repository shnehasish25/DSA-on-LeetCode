/*
- ============================================================
- Problem   : Delete Node in a Linked List
- LeetCode  : https://leetcode.com/problems/delete-node-in-a-linked-list/
- Problem # : 237
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Since we aren't given the head of the list, we cannot traverse to find the previous node.
- Instead, copy the value of the next node into the current node, then delete the next node by bypassing it.
 *
- Time Complexity  : O(1)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node's value into the current node
        node->val = node->next->val;
        
        // Save pointer to the node we are going to delete to free memory
        ListNode* toDelete = node->next;
        
        // Bypass the next node
        node->next = node->next->next;
        
        // Clean up
        delete toDelete;
    }
};

/*
- Key Learnings:
- This is a classic "trick" question. You don't actually delete the node you're given; you transform it into the next node, and delete the next one instead.
- It operates in strictly O(1) time because no traversal is required.
 *
- Status: Accepted
 */