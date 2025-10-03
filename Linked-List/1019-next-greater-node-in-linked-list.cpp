/*
- ============================================================
- Problem   : Next Greater Node In Linked List
- LeetCode  : https://leetcode.com/problems/next-greater-node-in-linked-list/
- Problem # : 1019
- Difficulty: Medium
- Topic     : Linked List, Stack, Monotonic Stack
 *
- Approach:
- Use a monotonic decreasing stack that stores pairs of {value, index}.
- As you traverse the list, if you encounter a value greater than the stack's top, pop the stack and update the result array for that popped index.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> st;
        int index = 0;
        
        ListNode* curr = head;
        while (curr) {
            res.push_back(0); // Initialize with 0
            while (!st.empty() && st.top().first < curr->val) {
                res[st.top().second] = curr->val;
                st.pop();
            }
            st.push({curr->val, index});
            index++;
            curr = curr->next;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The Monotonic Stack pattern applies to Linked Lists just as easily as Arrays.
- Since we can't look backwards in a singly linked list, we must store unresolved indices in the stack to update them later.
 *
- Status: Accepted
 */