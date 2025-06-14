/*
- ============================================================
- Problem   : Reverse Linked List
- LeetCode  : https://leetcode.com/problems/reverse-linked-list/
- Problem # : 206
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- Use three pointers (prev, curr, and a temporary path) to iteratively reverse the links.
- At each step, save the next node, reverse the current node's pointer to point to prev, and shift the pointers forward.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* path = curr->next;  
            curr->next = prev;            
            prev = curr;                  
            curr = path;                  
        }
        
        return prev; 
    }
};

/*
- Key Learnings:
- Always store the next node temporarily before overwriting curr->next so you don't lose access to the rest of the list.
- When the traversal finishes (curr == nullptr), the prev pointer correctly lands on the new head of the reversed list.
 *
- Status: Accepted
 */