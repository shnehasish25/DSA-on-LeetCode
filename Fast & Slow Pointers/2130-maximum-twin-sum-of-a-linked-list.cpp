/*
- ============================================================
- Problem   : Maximum Twin Sum of a Linked List
- LeetCode  : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
- Problem # : 2130
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Find the middle using fast/slow pointers.
- Reverse the second half of the list in place, then iterate both halves simultaneously to find the maximum sum of pairs.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev = nullptr, *curr = slow;
        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        int maxSum = 0;
        ListNode *p1 = head, *p2 = prev;
        while (p2 != nullptr) {
            maxSum = max(maxSum, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return maxSum;
    }
};

/*
- Key Learnings:
- Twin pair mapping requires assessing the start and end of a structure moving inward. 
- For Linked Lists, finding the middle and reversing the back half simulates moving "backward" from the tail.
 *
- Status: Accepted
 */