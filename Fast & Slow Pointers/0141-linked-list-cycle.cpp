/*
- ============================================================
- Problem   : Linked List Cycle
- LeetCode  : https://leetcode.com/problems/linked-list-cycle/
- Problem # : 141
- Difficulty: Easy
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use Floyd's Cycle-Finding Algorithm (Tortoise and Hare).
- Move a slow pointer one step and a fast pointer two steps. If they meet, there is a cycle.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

/*
- Key Learnings:
- The fast pointer will eventually "lap" the slow pointer if a cycle exists.
- Checking both fast and fast->next prevents null pointer dereferencing on list termination.
 *
- Status: Accepted
 */