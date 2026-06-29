/*
- ============================================================
- Problem   : K Radius Subarray Averages
- LeetCode  : https://leetcode.com/problems/k-radius-subarray-averages/
- Problem # : 2090
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- The window size is strictly (2 * k + 1). Initialize the result array with -1s.
- Keep a running sum of the window. When the window hits the required size, calculate the average and assign it to the 'i - k' index (the center).
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (excluding output array)
- ============================================================
 */

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        int window_size = 2 * k + 1;
        
        if (window_size > n) return res;
        
        long long current_sum = 0; // Prevent overflow
        
        for (int i = 0; i < n; i++) {
            current_sum += nums[i];
            
            if (i >= window_size) {
                current_sum -= nums[i - window_size];
            }
            
            if (i >= window_size - 1) {
                res[i - k] = current_sum / window_size;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The "Radius" implies the center element requires 'k' elements on the left and 'k' on the right.
- Calculating the center dynamically using 'i - k' avoids messy left/right boundary tracking. Use long long for sums to avoid integer overflow.
 *
- Status: Accepted
 */