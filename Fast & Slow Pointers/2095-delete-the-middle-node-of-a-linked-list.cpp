/*
- ============================================================
- Problem   : Delete the Middle Node of a Linked List
- LeetCode  : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
- Problem # : 2095
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use fast and slow pointers, but stagger them by initializing fast to head->next->next. 
- When fast reaches the end, slow will be exactly one node before the middle, making deletion trivial.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return head;
    }
};

/*
- Key Learnings:
- Staggering the 'fast' pointer start position is a clever way to ensure the 'slow' pointer lands on the node *preceding* the target.
- Direct pointer rewiring provides O(1) space modification.
 *
- Status: Accepted
 */