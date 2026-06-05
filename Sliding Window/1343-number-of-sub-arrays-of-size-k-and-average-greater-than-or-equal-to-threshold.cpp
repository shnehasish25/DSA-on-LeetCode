/*
- ============================================================
- Problem   : Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
- LeetCode  : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
- Problem # : 1343
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Instead of computing division dynamically, multiply the threshold by 'k' to get a target sum.
- Maintain a fixed sliding window of size 'k' and check if its sum is >= the target sum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target_sum = k * threshold;
        int current_sum = 0, count = 0;
        
        // Initial window
        for (int i = 0; i < k; i++) {
            current_sum += arr[i];
        }
        if (current_sum >= target_sum) count++;
        
        // Slide window
        for (int i = k; i < arr.size(); i++) {
            current_sum += arr[i] - arr[i - k];
            if (current_sum >= target_sum) count++;
        }
        
        return count;
    }
};

/*
- Key Learnings:
- (Average >= Threshold) mathematically means (Sum / k >= Threshold), which means (Sum >= Threshold * k).
- Always convert division conditions into multiplication conditions to avoid floating-point math entirely.
 *
- Status: Accepted
 */