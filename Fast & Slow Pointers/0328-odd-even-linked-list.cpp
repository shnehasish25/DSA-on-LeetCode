/*
- ============================================================
- Problem   : Odd Even Linked List
- LeetCode  : https://leetcode.com/problems/odd-even-linked-list/
- Problem # : 328
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Maintain two separate pointers forming two virtual lists: one for odd indices, one for even indices.
- Traverse the list stringing odds together and evens together, then append the even head to the odd tail.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
};

/*
- Key Learnings:
- You don't need to create new nodes. You can physically untangle one linked list into two simultaneous tracks in a single pass.
- Keeping an 'evenHead' anchor is necessary to stitch the two tracks back together at the end.
 *
- Status: Accepted
 */