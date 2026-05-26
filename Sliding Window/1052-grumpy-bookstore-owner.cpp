/*
- ============================================================
- Problem   : Grumpy Bookstore Owner
- LeetCode  : https://leetcode.com/problems/grumpy-bookstore-owner/
- Problem # : 1052
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Calculate a base level of satisfaction (when grumpy == 0).
- Run a fixed-size sliding window of length 'minutes' to find the maximum *extra* customers that can be satisfied by suppressing the grumpiness (grumpy == 1).
- Total = base satisfaction + max extra satisfaction.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base_satisfaction = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                base_satisfaction += customers[i];
            }
        }
        
        int current_extra = 0, max_extra = 0;
        
        // Initial window setup
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                current_extra += customers[i];
            }
        }
        max_extra = current_extra;
        
        // Slide window
        for (int i = minutes; i < customers.size(); i++) {
            if (grumpy[i] == 1) current_extra += customers[i];
            if (grumpy[i - minutes] == 1) current_extra -= customers[i - minutes];
            
            max_extra = max(max_extra, current_extra);
        }
        
        return base_satisfaction + max_extra;
    }
};

/*
- Key Learnings:
- Decoupling the "guaranteed" elements from the "conditional" elements allows you to only run the sliding window on the delta (extra satisfied customers).
- Applying the fixed window only to the grumpy indices vastly simplifies the calculation logic.
 *
- Status: Accepted
 */