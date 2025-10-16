/*
- ============================================================
- Problem   : Convert Binary Number in a Linked List to Integer
- LeetCode  : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
- Problem # : 1290
- Difficulty: Easy
- Topic     : Linked List, Math
 *
- Approach:
- Treat the list as a stream of bits. 
- Initialize result to 0. For each node, shift the result left by 1 (multiply by 2) and add (or bitwise OR) the node's value.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head) {
            res = (res << 1) | head->val;
            head = head->next;
        }
        return res;
    }
};

/*
- Key Learnings:
- Moving down a linked list representing digits is identical to shifting binary bits.
- Using left-shift (<< 1) and Bitwise OR (|) is marginally faster and functionally identical to (res * 2) + val.
 *
- Status: Accepted
 */