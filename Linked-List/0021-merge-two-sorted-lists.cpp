/*
- ============================================================
- Problem   : Merge Two Sorted Lists
- LeetCode  : https://leetcode.com/problems/merge-two-sorted-lists/
- Problem # : 21
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- Use a dummy node. Compare the heads of both lists, append the smaller one to the dummy's tail, and advance the respective pointer.
- Append any remaining nodes directly at the end.
 *
- Time Complexity  : O(n + m)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

/*
- Key Learnings:
- Stack-allocating the dummy node (ListNode dummy) instead of heap-allocating (new ListNode) avoids the need to run 'delete' later.
- Attaching the remaining non-null list entirely in O(1) time is the key optimization over arrays.
 *
- Status: Accepted
 */