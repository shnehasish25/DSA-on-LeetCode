/*
- ============================================================
- Problem   : Remove Nth Node From End of List
- LeetCode  : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
- Problem # : 19
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use a dummy node. Send a fast pointer 'n' steps ahead.
- Move both fast and slow pointers until fast reaches the end. Slow will now point to the node just before the target.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/*
- Key Learnings:
- The "Gap" technique: creating an 'n' sized gap between fast and slow ensures slow lands exactly where you need it when fast hits null.
- Using a dummy node avoids edge case nightmares (like deleting the head itself).
 *
- Status: Accepted
 */