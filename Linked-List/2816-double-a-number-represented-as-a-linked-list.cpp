/*
- ============================================================
- Problem   : Double a Number Represented as a Linked List
- LeetCode  : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
- Problem # : 2816
- Difficulty: Medium
- Topic     : Linked List, Math, Stack
 *
- Approach:
- A number multiplied by 2 will only carry over if the current digit is >= 5.
- We can traverse the list forward. If a node's value is >= 5, we know it will carry a 1 to the previous node.
- If the head itself is >= 5, we must prepend a new node with value 1.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) {
            head = new ListNode(1, head);
        }
        
        ListNode* curr = head;
        while (curr) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next && curr->next->val >= 5) {
                curr->val += 1;
            }
            curr = curr->next;
        }
        
        return head;
    }
};

/*
- Key Learnings:
- Multiplication by 2 is special: the maximum carry is always 1, and it strictly depends on if the next digit is >= 5.
- This mathematical insight completely bypasses the need to reverse the linked list or use a stack!
 *
- Status: Accepted
 */