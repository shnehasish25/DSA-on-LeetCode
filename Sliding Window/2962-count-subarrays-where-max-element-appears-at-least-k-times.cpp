/*
- ============================================================
- Problem   : Count Subarrays Where Max Element Appears at Least K Times
- LeetCode  : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
- Problem # : 2962
- Difficulty: Medium
- Topic     : Array, Sliding Window
 *
- Approach:
- Find the maximum element in the array first.
- Slide a window. Keep a count of how many times the max element appears.
- If count == k, every subarray extending to the right is valid. Add (n - right) to the answer and shrink from the left.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, count = 0, n = nums.size();
        
        for (int right = 0; right < n; right++) {
            if (nums[right] == max_val) count++;
            
            while (count == k) {
                ans += (n - right);
                if (nums[left] == max_val) count--;
                left++;
            }
        }
        
        return ans;
    }
};

/*
- Key Learnings:
- The combinatorial trick: once a window meets the "at least K" condition, ALL possible extensions of that window to the end of the array are also valid, adding (n - right) instantly.
- Finding the max element up front (O(n)) simplifies the window condition to a simple integer match.
 *
- Status: Accepted
 */