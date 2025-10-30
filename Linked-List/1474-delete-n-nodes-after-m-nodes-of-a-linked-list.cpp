/*
- ============================================================
- Problem   : Delete N Nodes After M Nodes of a Linked List (Premium)
- LeetCode  : https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
- Problem # : 1474
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- Traverse the list. Use a loop to skip exactly 'm' nodes.
- Once 'm' nodes are skipped, use another loop to delete exactly 'n' nodes by bypassing them.
- Repeat until the end of the list is reached.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr = head;
        
        while (curr) {
            // Skip M nodes
            int mCount = m;
            while (curr && mCount > 1) {
                curr = curr->next;
                mCount--;
            }
            
            if (!curr) break; // Reached the end
            
            // Delete N nodes
            ListNode* del = curr->next;
            int nCount = n;
            while (del && nCount > 0) {
                ListNode* temp = del;
                del = del->next;
                delete temp;
                nCount--;
            }
            
            curr->next = del;
            curr = del;
        }
        
        return head;
    }
};

/*
- Key Learnings:
- A straightforward simulation. Breaking the traversal into two distinct bounded while-loops (one for keeping, one for deleting) is much cleaner than using a complex modulo counter.
 *
- Status: Accepted
 */