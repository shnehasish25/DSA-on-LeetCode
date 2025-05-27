/*
- ============================================================
- Problem   : Insertion Sort List
- LeetCode  : https://leetcode.com/problems/insertion-sort-list/
- Problem # : 147
- Difficulty: Medium
- Topic     : Linked List, Sorting
 *
- Approach:
- Use a dummy node to represent the sorted portion of the list.
- Iterate through the original list, for each node, search from the dummy node for the correct place to insert it.
 *
- Time Complexity  : O(n^2)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* prev = dummy;
            
            // Find insertion point
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            ListNode* nextNode = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            
            curr = nextNode;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- A dummy node makes insertion sorting vastly easier because you don't have to write edge case logic for replacing the head.
- Though it is O(n^2), pointer rewiring means zero memory allocations are needed compared to array shifting.
 *
- Status: Accepted
 */