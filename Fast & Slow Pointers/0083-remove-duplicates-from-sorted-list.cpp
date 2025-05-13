/*
- ============================================================
- Problem   : Remove Duplicates from Sorted List
- LeetCode  : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
- Problem # : 83
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- Traverse the list with a single pointer.
- If the current node's value matches the next node's value, skip the next node by rewiring the 'next' pointer.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};

/*
- Key Learnings:
- Since the list is already sorted, duplicates are guaranteed to be adjacent.
- Always remember to free memory (delete) in C++ to avoid memory leaks when removing nodes.
 *
- Status: Accepted
 */