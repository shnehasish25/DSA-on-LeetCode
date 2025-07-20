/*
- ============================================================
- Problem   : Maximum Score Of Spliced Array
- LeetCode  : https://leetcode.com/problems/maximum-score-of-spliced-array/
- Problem # : 2321
- Difficulty: Hard
- Topic     : Array, Dynamic Programming
 *
- Approach:
- Splicing array 1 into array 2 yields a net gain of (nums1[i] - nums2[i]). 
- Calculate the maximum possible subarray sum of these differences using Kadane's algorithm for both combinations (1 into 2, and 2 into 1).
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int kadane(vector<int>& a, vector<int>& b) {
        int max_gain = 0;
        int current_gain = 0;
        for (int i = 0; i < a.size(); i++) {
            current_gain = max(0, current_gain + (b[i] - a[i]));
            max_gain = max(max_gain, current_gain);
        }
        return max_gain;
    }
    
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;
        
        int ans1 = sum1 + kadane(nums1, nums2);
        int ans2 = sum2 + kadane(nums2, nums1);
        
        return max(ans1, ans2);
    }
};

/*
- Key Learnings:
- The delta (difference) array trick transforms a complex combination problem into a simple contiguous subarray sum.
- When evaluating mutual operations on two arrays, running a generic helper function twice is cleaner than a massive inline loop.
 *
- Status: Accepted
 */