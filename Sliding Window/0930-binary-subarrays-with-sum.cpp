/*
- ============================================================
- Problem   : Binary Subarrays With Sum
- LeetCode  : https://leetcode.com/problems/binary-subarrays-with-sum/
- Problem # : 930
- Difficulty: Medium
- Topic     : Array, Sliding Window, Prefix Sum
 *
- Approach:
- Find subarrays with EXACTLY 'goal' sum by calculating (Subarrays with <= goal) - (Subarrays with <= goal - 1).
- Use a sliding window helper function to find subarrays with at most 'k' sum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0, count = 0, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

/*
- Key Learnings:
- "Exact K" problems using Sliding Windows are tricky because of zeroes (which don't change the sum).
- The mathematical trick Exact(K) = AtMost(K) - AtMost(K-1) transforms complex prefix problems into two simple sliding windows.
 *
- Status: Accepted
 */