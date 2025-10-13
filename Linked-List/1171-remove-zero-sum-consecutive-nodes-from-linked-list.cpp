/*
- ============================================================
- Problem   : Remove Zero Sum Consecutive Nodes from Linked List
- LeetCode  : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
- Problem # : 1171
- Difficulty: Medium
- Topic     : Linked List, Hash Table, Prefix Sum
 *
- Approach:
- Use Prefix Sum logic (like Subarray Sum Equals K).
- Keep a hash map of prefix sum to the last node that had that sum.
- If a sum repeats, the nodes strictly between the two occurrences sum to zero. Bypass them using pointer reassignment.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <unordered_map>

using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefix_map;
        
        int prefix = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefix += curr->val;
            prefix_map[prefix] = curr; // Overwrites to the LAST occurrence
        }
        
        prefix = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefix += curr->val;
            curr->next = prefix_map[prefix]->next; // Instantly jump over the zero-sum sublist
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- Prefix Sum + Hash Map works flawlessly on Linked Lists. 
- Overwriting the prefix sum to the *last* occurrence automatically maximizes the deleted segment, preventing multiple messy overlapping deletions.
 *
- Status: Accepted
 */