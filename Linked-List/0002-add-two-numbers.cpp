/*
- ============================================================
- Problem   : Add Two Numbers
- LeetCode  : https://leetcode.com/problems/add-two-numbers/
- Problem # : 2
- Difficulty: Medium
- Topic     : Linked List, Math
 *
- Approach:
- Traverse both lists simultaneously. Add the values of the nodes along with any carry from the previous step.
- Create a new node with (sum % 10) and pass (sum / 10) as the new carry.
 *
- Time Complexity  : O(max(m, n))
- Space Complexity : O(max(m, n)) for the result list
- ============================================================
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- The 'carry != 0' condition inside the while loop elegantly handles cases where an extra digit is created at the very end (e.g., 9 + 1 = 10).
- Using a dummy head prevents repetitive null-checking when attaching the first node.
 *
- Status: Accepted
 */