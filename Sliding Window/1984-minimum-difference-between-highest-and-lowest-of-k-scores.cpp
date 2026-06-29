/*
- ============================================================
- Problem   : Minimum Difference Between Highest and Lowest of K Scores
- LeetCode  : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
- Problem # : 1984
- Difficulty: Easy
- Topic     : Array, Sliding Window, Sorting
 *
- Approach:
- Sort the array first to group the closest scores together.
- Use a fixed window of size 'k' and calculate the difference between the last element and first element in that window (nums[i+k-1] - nums[i]).
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            min_diff = min(min_diff, nums[i + k - 1] - nums[i]);
        }
        
        return min_diff;
    }
};

/*
- Key Learnings:
- Sorting allows a sliding window to represent the subset with the minimal difference, bypassing complex subarray combinations.
- A window of size 'k' starting at 'i' always ends at 'i + k - 1'.
 *
- Status: Accepted
 */