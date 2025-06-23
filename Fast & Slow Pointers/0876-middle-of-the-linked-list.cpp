/*
- ============================================================
- Problem   : Middle of the Linked List
- LeetCode  : https://leetcode.com/problems/middle-of-the-linked-list/
- Problem # : 876
- Difficulty: Easy
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use two pointers: a slow one that advances 1 step and a fast one that advances 2 steps.
- When the fast pointer hits the end, the slow pointer is exactly in the middle.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};

/*
- Key Learnings:
- The standard way to locate the middle of a list without iterating twice.
- If the list has an even number of nodes, this returns the second middle node, which fits most problem requirements.
 *
- Status: Accepted
 */