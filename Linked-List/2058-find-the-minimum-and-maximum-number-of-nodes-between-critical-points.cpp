/*
- ============================================================
- Problem   : Find the Minimum and Maximum Number of Nodes Between Critical Points
- LeetCode  : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
- Problem # : 2058
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Track the index of critical points (local maxima and minima).
- The maximum distance is strictly between the first critical point and the last.
- The minimum distance is the smallest gap between any two adjacent critical points.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        int first_crit = -1, prev_crit = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first_crit == -1) {
                    first_crit = idx;
                } else {
                    min_dist = min(min_dist, idx - prev_crit);
                }
                prev_crit = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        if (min_dist == INT_MAX) return {-1, -1};
        
        return {min_dist, prev_crit - first_crit};
    }
};

/*
- Key Learnings:
- You don't need an array to store all critical points. Just storing the 'first' index and the 'previous' index is enough to calculate both global limits.
- Requires traversing with a 'prev' pointer alongside 'curr'.
 *
- Status: Accepted
 */