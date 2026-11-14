/*
- ============================================================
- Problem   : Squares of a Sorted Array
- LeetCode  : https://leetcode.com/problems/squares-of-a-sorted-array/
- Problem # : 977
- Difficulty: Easy
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Since the array is sorted, the largest squares will always be at the extreme ends (either large positive or large negative numbers).
- Use two pointers at both ends, compare their absolute values, square the larger one, and place it at the end of the result array.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n) for the output array
- ============================================================
 */

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = n - 1;
        int pos = n - 1; // Start filling the result array from the back
        
        while (left <= right) {
            // 1. Compare absolute values at both extremes
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--; // Move backward in the result array
        }
        
        return result;
    }
};

/*
- Key Learnings:
- Squaring and then sorting takes O(n log n), but utilizing the sorted input and two pointers brings it down to an optimal O(n).
- Building the output array from right to left (largest to smallest) is the key insight for this problem.
 *
- Status: Accepted
 */