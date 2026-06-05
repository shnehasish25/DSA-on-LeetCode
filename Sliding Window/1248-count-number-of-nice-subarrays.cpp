/*
- ============================================================
- Problem   : Count Number of Nice Subarrays
- LeetCode  : https://leetcode.com/problems/count-number-of-nice-subarrays/
- Problem # : 1248
- Difficulty: Medium
- Topic     : Array, Sliding Window, Math
 *
- Approach:
- A "nice" subarray has exactly 'k' odd numbers. Treat odd numbers as 1 and even numbers as 0.
- Apply the AtMost(k) - AtMost(k-1) sliding window technique used in "Binary Subarrays With Sum".
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0, count = 0, odds = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) odds++;
            while (odds > k) {
                if (nums[left] % 2 != 0) odds--;
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

/*
- Key Learnings:
- Pattern recognition: "Count exactly K constraints" in an array almost always reduces to the AtMost(K) - AtMost(K-1) template.
- Modulo 2 converts properties (odd/even) into binary states (1/0) enabling sum-based windowing.
 *
- Status: Accepted
 */