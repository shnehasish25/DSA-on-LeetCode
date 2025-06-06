/*
- ============================================================
- Problem   : Sort List
- LeetCode  : https://leetcode.com/problems/sort-list/
- Problem # : 148
- Difficulty: Medium
- Topic     : Linked List, Two Pointers, Divide and Conquer
 *
- Approach:
- Use Merge Sort. Find the middle of the list using fast/slow pointers.
- Recursively sort both halves, then merge the two sorted lists.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(log n) (due to recursion stack)
- ============================================================
 */

class Solution {
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
            else { tail->next = l2; l2 = l2->next; }
            tail = tail->next;
        }
        tail->next = (l1) ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        
        ListNode* left_sorted = sortList(head);
        ListNode* right_sorted = sortList(right);
        
        return merge(left_sorted, right_sorted);
    }
};

/*
- Key Learnings:
- Merge Sort is the most efficient sorting algorithm for linked lists because elements don't need to be physically shifted, just re-linked.
- Fast/Slow pointers are critical to split the list accurately in O(n) during the divide step.
 *
- Status: Accepted
 */