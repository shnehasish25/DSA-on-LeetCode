/*
- ============================================================
- Problem   : Add Two Numbers II
- LeetCode  : https://leetcode.com/problems/add-two-numbers-ii/
- Problem # : 445
- Difficulty: Medium
- Topic     : Linked List, Math, Stack
 *
- Approach:
- Since digits are stored in forward order, use two stacks to reverse the traversal order.
- Pop from stacks, add values and carry, and build the resulting linked list backwards by continuously inserting at the head.
 *
- Time Complexity  : O(m + n)
- Space Complexity : O(m + n)
- ============================================================
 */

#include <stack>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) { s1.push(l1->val); l1 = l1->next; }
        while (l2) { s2.push(l2->val); l2 = l2->next; }
        
        ListNode* head = nullptr;
        int carry = 0;
        
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) { sum += s1.top(); s1.pop(); }
            if (!s2.empty()) { sum += s2.top(); s2.pop(); }
            
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
            
            carry = sum / 10;
        }
        
        return head;
    }
};

/*
- Key Learnings:
- A stack is the perfect O(n) space substitute for physically reversing linked lists when modification of the input is forbidden.
- Inserting nodes at the 'head' continuously builds the list in forward order naturally.
 *
- Status: Accepted
 */