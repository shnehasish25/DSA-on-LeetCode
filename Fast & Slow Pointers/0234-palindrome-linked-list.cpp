/*
- ============================================================
- Problem   : Palindrome Linked List
- LeetCode  : https://leetcode.com/problems/palindrome-linked-list/
- Problem # : 234
- Difficulty: Easy
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Use fast/slow pointers to find the middle.
- Reverse the second half of the list, then iterate and compare both halves node by node.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev = nullptr;
        while (slow != nullptr) {
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        ListNode *left = head, *right = prev;
        while (right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

/*
- Key Learnings:
- Combining Fast/Slow with list reversal achieves an O(1) space solution where an array copy would cost O(n).
- Good practice dictates reversing the list back before exiting, though LeetCode doesn't strictly check for it here.
 *
- Status: Accepted
 */