/*
- ============================================================
- Problem   : Swapping Nodes in a Linked List
- LeetCode  : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
- Problem # : 1721
- Difficulty: Medium
- Topic     : Linked List, Two Pointers
 *
- Approach:
- Traverse to find the k-th node from the beginning.
- Use the standard "k-gap" two-pointer technique to find the k-th node from the end.
- Simply swap the integer values of these two nodes.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *second = head, *fast = head;
        
        // Find the k-th node from the beginning
        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }
        first = fast;
        
        // Use gap to find k-th node from the end
        while (fast->next) {
            second = second->next;
            fast = fast->next;
        }
        
        swap(first->val, second->val);
        
        return head;
    }
};

/*
- Key Learnings:
- Swapping the 'values' is perfectly legal and vastly simpler than physically swapping the node pointers (which requires tracking previous nodes and handling adjacent edge cases).
- The gap pointer technique seamlessly finds bounds from the tail in a single pass.
 *
- Status: Accepted
 */