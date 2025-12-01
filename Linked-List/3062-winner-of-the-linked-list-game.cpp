/*
- ============================================================
- Problem   : Winner of the Linked List Game
- LeetCode  : https://leetcode.com/problems/winner-of-the-linked-list-game/
- Problem # : 3062
- Difficulty: Easy
- Topic     : Linked List
 *
- Approach:
- The list has an even number of nodes. Traverse it in pairs.
- Compare curr->val (even index) and curr->next->val (odd index). Keep a tally of points.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    string gameResult(ListNode* head) {
        int even_points = 0;
        int odd_points = 0;
        
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val > curr->next->val) {
                even_points++;
            } else if (curr->val < curr->next->val) {
                odd_points++;
            }
            curr = curr->next->next;
        }
        
        if (even_points > odd_points) return "Even";
        if (odd_points > even_points) return "Odd";
        return "Tie";
    }
};

/*
- Key Learnings:
- Basic pair-wise traversal. Advancing the pointer by two (curr = curr->next->next) safely steps through pairs.
 *
- Status: Accepted
 */