/*
- ============================================================
- Problem   : Rotate List
- LeetCode  : https://leetcode.com/problems/rotate-list/
- Problem # : 61
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Find the list length and connect the tail to the head to form a circular list.
- Find the new tail (length - k % length - 1), break the cycle, and assign the new head.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        tail->next = head; // form circle
        k = k % length;
        
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail-- > 0) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // break circle
        
        return newHead;
    }
};

/*
- Key Learnings:
- Turning the list into a loop first makes rotation a simple math problem (length - k % length) rather than a complex node shifting puzzle.
- 'k' can be larger than length, hence the modulo is strictly required.
 *
- Status: Accepted
 */