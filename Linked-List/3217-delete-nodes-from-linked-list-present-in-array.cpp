/*
- ============================================================
- Problem   : Delete Nodes From Linked List Present in Array
- LeetCode  : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
- Problem # : 3217
- Difficulty: Medium
- Topic     : Linked List, Hash Table
 *
- Approach:
- Push all elements of the target array into an unordered_set.
- Use a dummy node to handle head deletions, and iterate through the list cleanly removing nodes whose values exist in the set.
 *
- Time Complexity  : O(n + m)
- Space Complexity : O(m)
- ============================================================
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> targets(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        
        while (curr->next) {
            if (targets.count(curr->next->val)) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

/*
- Key Learnings:
- This is a direct combination of "Remove Linked List Elements" and "Linked List Components".
- Generating a Hash Set from a vector is optimized in C++ via the range constructor (nums.begin(), nums.end()).
 *
- Status: Accepted
 */