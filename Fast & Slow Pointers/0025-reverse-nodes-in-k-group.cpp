/*
- ============================================================
- Problem   : Reverse Nodes in k-Group
- LeetCode  : https://leetcode.com/problems/reverse-nodes-in-k-group/
- Problem # : 25
- Difficulty: Hard
- Topic     : Linked List, Recursion
 *
- Approach:
- Count if there are at least k nodes remaining. If not, leave them as is.
- If there are, reverse the next k nodes using standard list reversal, then recursively call the function for the rest.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n / k) for recursion stack, or O(1) if iterative
- ============================================================
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        int count = 0;
        
        // 1. Check if we have k nodes
        while (cursor != nullptr && count != k) {
            cursor = cursor->next;
            count++;
        }
        
        // 2. If we have k nodes, reverse them
        if (count == k) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // 3. head is now the tail of this reversed group. Connect it to the next reversed group.
            head->next = reverseKGroup(cursor, k);
            return prev; // prev is the new head of this reversed group
        }
        
        return head; // Less than k nodes, return as is
    }
};

/*
- Key Learnings:
- Breaking a Hard linked list problem into a loop of smaller Easy problems (Reverse Linked List) drastically simplifies the logic.
- Recursion cleanly handles the "stitching together" of the reversed chunks.
 *
- Status: Accepted
 */