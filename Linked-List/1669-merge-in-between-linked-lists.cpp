/*
- ============================================================
- Problem   : Merge In Between Linked Lists
- LeetCode  : https://leetcode.com/problems/merge-in-between-linked-lists/
- Problem # : 1669
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Find the node just before index 'a' (node_a) and the node at index 'b' (node_b).
- Find the tail of list2.
- Connect node_a to the head of list2, and connect the tail of list2 to the node AFTER node_b.
 *
- Time Complexity  : O(n + m)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        for (int i = 0; i < a - 1; i++) {
            start = start->next;
        }
        
        ListNode* end = start;
        for (int i = 0; i <= b - a + 1; i++) {
            end = end->next;
        }
        
        ListNode* tail2 = list2;
        while (tail2->next) {
            tail2 = tail2->next;
        }
        
        start->next = list2;
        tail2->next = end;
        
        return list1;
    }
};

/*
- Key Learnings:
- Very mechanical pointer manipulation. Finding the exact breaking points (a - 1) and (b + 1) is the only real logic needed.
- O(1) space is trivially achieved because we just rewire existing memory addresses.
 *
- Status: Accepted
 */