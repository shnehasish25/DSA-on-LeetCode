/*
- ============================================================
- Problem   : Remove Duplicates from Sorted List II
- LeetCode  : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
- Problem # : 82
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use a dummy node pointing to head, with 'prev' on dummy and 'curr' on head.
- When duplicates are detected, advance 'curr' past all of them, then link 'prev->next' directly to the first distinct node.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // skip all duplicates
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- The dummy node is non-negotiable here since the original head might be part of a duplicate cluster and completely deleted.
- 'prev' acts as the slow pointer cementing the valid list, while 'curr/head' acts as the fast scanner.
 *
- Status: Accepted
 */