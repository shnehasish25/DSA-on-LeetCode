/*
- ============================================================
- Problem   : Reorder List
- LeetCode  : https://leetcode.com/problems/reorder-list/
- Problem # : 143
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Find the middle using fast and slow pointers.
- Reverse the second half, then merge the two halves by alternating nodes from each.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr;
        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode *p1 = head, *p2 = prev;
        while (p2 != nullptr) {
            ListNode *t1 = p1->next, *t2 = p2->next;
            p1->next = p2;
            p2->next = t1;
            p1 = t1;
            p2 = t2;
        }
    }
};

/*
- Key Learnings:
- This is a composite problem testing 3 distinct linked list patterns: find mid, reverse list, and merge lists.
- Cutting the list into two cleanly (setting slow->next = nullptr) is critical to avoid cycles during the merge phase.
 *
- Status: Accepted
 */