/*
- ============================================================
- Problem   : Swap Nodes in Pairs
- LeetCode  : https://leetcode.com/problems/swap-nodes-in-pairs/
- Problem # : 24
- Difficulty: Medium
- Topic     : Linked List, Recursion
 *
- Approach:
- Use a dummy node to handle the head swap seamlessly.
- Maintain a 'prev' pointer, and swap the two nodes immediately following it, then advance 'prev' by two.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move forward
            prev = first;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/*
- Key Learnings:
- A dummy node acts as an anchor. It ensures that the first pair swap doesn't lose track of the new head of the list.
- Pointer swapping is order-dependent: always save the rest of the list before modifying links.
 *
- Status: Accepted
 */