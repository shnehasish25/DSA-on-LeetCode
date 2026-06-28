/*
- ============================================================
- Problem   : Frequency of the Most Frequent Element
- LeetCode  : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
- Problem # : 1838
- Difficulty: Medium
- Topic     : Array, Sliding Window, Sorting, Greedy
 *
- Approach:
- Sort the array first so elements can be incremented toward the maximum value in the window (the rightmost element).
- The operation cost to make all elements in the window equal to nums[right] is: (nums[right] * window_length) - sum_of_window.
- If this cost exceeds 'k', shrink the window from the left.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long current_sum = 0;
        int left = 0, max_freq = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            long long target_sum = (long long)nums[right] * (right - left + 1);
            
            while (target_sum - current_sum > k) {
                current_sum -= nums[left];
                left++;
                target_sum = (long long)nums[right] * (right - left + 1);
            }
            
            max_freq = max(max_freq, right - left + 1);
        }
        
        return max_freq;
    }
};

/*
- Key Learnings:
- The insight is that the "target" value to match is always the largest value in a sorted window. 
- Calculating the exact operations needed using the area of a rectangle (target * length) minus the actual sum is a brilliant mathematical shortcut.
 *
- Status: Accepted
 */