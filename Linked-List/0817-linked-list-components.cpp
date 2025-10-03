/*
- ============================================================
- Problem   : Linked List Components
- LeetCode  : https://leetcode.com/problems/linked-list-components/
- Problem # : 817
- Difficulty: Medium
- Topic     : Linked List, Hash Table
 *
- Approach:
- Store the target numbers in an unordered_set for O(1) lookups.
- Traverse the linked list. A component is counted when we are currently on a node that exists in the set, BUT the next node is either null or NOT in the set.
 *
- Time Complexity  : O(n + m) where m is size of nums
- Space Complexity : O(m)
- ============================================================
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int components = 0;
        ListNode* curr = head;
        
        while (curr) {
            if (num_set.count(curr->val) && (!curr->next || !num_set.count(curr->next->val))) {
                components++;
            }
            curr = curr->next;
        }
        
        return components;
    }
};

/*
- Key Learnings:
- Identifying the "tail" of a component (the boundary where it breaks) is simpler than tracking the head of a component.
- Hash sets provide instantaneous O(1) checks during an O(n) list traversal.
 *
- Status: Accepted
 */