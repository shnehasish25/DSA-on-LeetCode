/*
- ============================================================
- Problem   : Linked List Cycle II
- LeetCode  : https://leetcode.com/problems/linked-list-cycle-ii/
- Problem # : 142
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Detect the cycle using fast and slow pointers.
- Upon intersection, reset one pointer to the head. Move both at 1x speed; they will collide at the cycle's start.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                ListNode *entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};

/*
- Key Learnings:
- The mathematical property of Floyd's algorithm ensures distance from head to cycle-start equals the distance from intersection to cycle-start.
- This entirely bypasses the need for an O(n) hash set to track visited nodes.
 *
- Status: Accepted
 */