/*
- ============================================================
- Problem   : Intersection of Two Linked Lists
- LeetCode  : https://leetcode.com/problems/intersection-of-two-linked-lists/
- Problem # : 160
- Difficulty: Easy
- Topic     : Hash Table, Linked List, Two Pointers
 *
- Approach:
- Use two pointers, one for each head.
- Traverse. When a pointer hits null, reset it to the head of the OTHER list. They will sync up and meet at the intersection.
 *
- Time Complexity  : O(m + n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        return pA;
    }
};

/*
- Key Learnings:
- By switching heads, both pointers travel exactly (Length A + Length B) distance. This perfectly aligns them to hit the intersection simultaneously.
- If there is no intersection, they will both hit 'nullptr' at the exact same time and safely return null.
 *
- Status: Accepted
 */