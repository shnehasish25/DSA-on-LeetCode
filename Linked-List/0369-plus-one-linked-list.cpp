/*
- ============================================================
- Problem   : Plus One Linked List (Premium)
- LeetCode  : https://leetcode.com/problems/plus-one-linked-list/
- Problem # : 369
- Difficulty: Medium
- Topic     : Linked List, Math
 *
- Approach:
- Find the rightmost node that is NOT a 9. 
- Increment that node by 1, and set all the trailing 9s to 0.
- If all nodes are 9 (or the list is 9->9), add a dummy node at the head, increment it, and set the rest to 0.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* notNine = dummy;
        
        // Find the rightmost non-9 node
        ListNode* curr = head;
        while (curr) {
            if (curr->val != 9) {
                notNine = curr;
            }
            curr = curr->next;
        }
        
        // Increment the non-9 node
        notNine->val += 1;
        
        // Set all nodes to the right of it to 0
        curr = notNine->next;
        while (curr) {
            curr->val = 0;
            curr = curr->next;
        }
        
        if (dummy->val == 1) {
            return dummy; // The entire original list was 9s
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- By scanning for the rightmost non-9 node, we instantly identify where the carry will terminate, eliminating the need to reverse the list or use a stack!
- This is an elegant mathematical optimization specific to base-10 addition.
 *
- Status: Accepted
 */