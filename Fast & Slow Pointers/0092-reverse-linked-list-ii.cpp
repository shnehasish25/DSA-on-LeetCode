/*
- ============================================================
- Problem   : Reverse Linked List II
- LeetCode  : https://leetcode.com/problems/reverse-linked-list-ii/
- Problem # : 92
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Traverse to the 'left' node, keeping track of the node just before it ('b').
- Perform a standard linked list reversal for exactly (right - left + 1) nodes.
- Reconnect the reversed sublist back to the main list.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        int num = right - left + 1;       
        ListNode* f = head;
        ListNode* b = nullptr;
        int pos = 1;

        while (pos < left) {
            b = f;
            f = f->next;
            pos++;
        }

        ListNode* curr = f;
        ListNode* prev = nullptr;

        while (num--) {
            ListNode* path = curr->next;  
            curr->next = prev;            
            prev = curr;                  
            curr = path;                  
        }

        if (b != nullptr) {
            b->next = prev;               
        } else {
            head = prev;                  
        }
        
        f->next = curr;                   

        return head;
    }
};

/*
- Key Learnings:
- Calculate the exact number of reversals needed (right - left + 1) to constrain the standard reversal algorithm.
- Handle the edge case where the reversal starts at the very first node (left == 1) carefully, as it changes the main head.
 *
- Status: Accepted
 */