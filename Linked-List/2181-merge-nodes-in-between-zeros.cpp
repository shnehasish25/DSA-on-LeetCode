/*
- ============================================================
- Problem   : Merge Nodes in Between Zeros
- LeetCode  : https://leetcode.com/problems/merge-nodes-in-between-zeros/
- Problem # : 2181
- Difficulty: Medium
- Topic     : Linked List, Simulation
 *
- Approach:
- Iterate through the list. Maintain a running sum between zero nodes.
- Instead of creating new nodes, rewrite the values of the existing zero nodes (acting as anchors) to save memory, and bypass the summed nodes.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* insert = head->next; // Start inserting at the first non-zero
        ListNode* curr = head->next;
        int sum = 0;
        
        while (curr) {
            if (curr->val != 0) {
                sum += curr->val;
            } else {
                insert->val = sum;
                sum = 0;
                if (curr->next) {
                    insert->next = curr->next;
                    insert = insert->next;
                } else {
                    insert->next = nullptr;
                }
            }
            curr = curr->next;
        }
        
        return head->next;
    }
};

/*
- Key Learnings:
- In-place modification of linked lists is vastly superior to dynamically allocating new nodes with "new ListNode()". 
- Using the zero-nodes as storage anchors guarantees O(1) space complexity.
 *
- Status: Accepted
 */