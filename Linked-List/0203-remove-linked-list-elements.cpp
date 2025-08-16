/*
- ============================================================
- Problem   : Remove Linked List Elements
- LeetCode  : https://leetcode.com/problems/remove-linked-list-elements/
- Problem # : 203
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- Use a dummy node pointing to the head. This cleanly handles edge cases where the head itself (or multiple consecutive heads) needs to be removed.
- Traverse maintaining a 'curr' pointer. Re-link 'curr->next' to skip over target values.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};

/*
- Key Learnings:
- Standard node deletion. Using 'ListNode dummy(0)' on the stack automatically cleans up the dummy node memory when the function exits.
- Do NOT advance 'curr' if a deletion happened, because the new 'curr->next' might also be the target value.
 *
- Status: Accepted
 */