/*
- ============================================================
- Problem   : Maximum Points You Can Obtain from Cards
- LeetCode  : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
- Problem # : 1423
- Difficulty: Medium
- Topic     : Array, Sliding Window, Prefix Sum
 *
- Approach:
- Selecting 'k' cards from the ends is mathematically identical to leaving a contiguous subarray of size (n - k) unselected.
- Find the minimum sum of a contiguous window of size (n - k) and subtract it from the total sum of the array.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = 0, n = cardPoints.size();
        for (int x : cardPoints) total_sum += x;
        
        int window_size = n - k;
        if (window_size == 0) return total_sum;
        
        int current_window_sum = 0;
        for (int i = 0; i < window_size; i++) {
            current_window_sum += cardPoints[i];
        }
        
        int min_window_sum = current_window_sum;
        for (int i = window_size; i < n; i++) {
            current_window_sum += cardPoints[i] - cardPoints[i - window_size];
            min_window_sum = min(min_window_sum, current_window_sum);
        }
        
        return total_sum - min_window_sum;
    }
};

/*
- Key Learnings:
- Reversing the problem constraints (finding the min discarded window instead of the max kept pieces) turns a complex two-sided extraction into a simple fixed sliding window.
- When constrained to pulling from the extremes, look at what gets left behind in the middle.
 *
- Status: Accepted
 */