/*
- ============================================================
- Problem   : Remove Nodes From Linked List
- LeetCode  : https://leetcode.com/problems/remove-nodes-from-linked-list/
- Problem # : 2487
- Difficulty: Medium
- Topic     : Linked List, Stack, Recursion
 *
- Approach:
- Reverse the list. Now, instead of deleting nodes smaller than ANY node to their right, we just delete nodes smaller than the MAXIMUM seen so far.
- Iterate the reversed list dropping smaller nodes, then reverse it back.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <algorithm>

using namespace std;

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        
        ListNode* curr = head;
        int max_val = curr->val;
        
        while (curr && curr->next) {
            if (curr->next->val < max_val) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
                max_val = curr->val;
            }
        }
        
        return reverseList(head);
    }
};

/*
- Key Learnings:
- While a monotonic stack naturally solves this, reversing the list achieves the exact same mathematical logic in O(1) auxiliary space instead of O(n).
- Any problem evaluating constraints strictly "to the right" becomes trivialized when the list is reversed.
 *
- Status: Accepted
 */