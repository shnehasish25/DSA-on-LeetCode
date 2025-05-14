/*
- ============================================================
- Problem   : Partition List
- LeetCode  : https://leetcode.com/problems/partition-list/
- Problem # : 86
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Create two separate dummy lists: one for values < x, one for values >= x.
- Traverse the original list, sorting nodes into the respective lists, then combine them.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeDummy = new ListNode(0);
        ListNode* afterDummy = new ListNode(0);
        
        ListNode* before = beforeDummy;
        ListNode* after = afterDummy;
        
        while (head != nullptr) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = nullptr; // Terminate the end list to prevent cycles
        before->next = afterDummy->next; // Stitch them together
        
        ListNode* result = beforeDummy->next;
        delete beforeDummy;
        delete afterDummy;
        
        return result;
    }
};

/*
- Key Learnings:
- Two dummy nodes allow for a clean, stable partition sort without needing complex in-place swaps.
- Always remember to set the final node of the 'after' list to nullptr, or you will create a cycle.
 *
- Status: Accepted
 */