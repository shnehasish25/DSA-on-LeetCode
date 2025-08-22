/*
- ============================================================
- Problem   : Linked List Random Node
- LeetCode  : https://leetcode.com/problems/linked-list-random-node/
- Problem # : 382
- Difficulty: Medium
- Topic     : Linked List, Math, Randomized
 *
- Approach:
- Use Reservoir Sampling. This guarantees uniform probability without needing to know the length of the list beforehand.
- As you iterate, pick the current node with probability 1/i.
 *
- Time Complexity  : O(n) per getRandom
- Space Complexity : O(1)
- ============================================================
 */

#include <cstdlib>

class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = head->val;
        ListNode* curr = head->next;
        int i = 2;
        
        while (curr) {
            if (rand() % i == 0) {
                res = curr->val;
            }
            curr = curr->next;
            i++;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Reservoir Sampling is a magical algorithm for streaming data of unknown length.
- "rand() % i == 0" exactly yields a 1/i probability, ensuring that every node ends up with a perfectly uniform 1/N chance of being selected.
 *
- Status: Accepted
 */