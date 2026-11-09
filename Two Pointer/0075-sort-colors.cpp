/*
- ============================================================
- Problem   : Sort Colors
- LeetCode  : https://leetcode.com/problems/sort-colors/
- Problem # : 75
- Difficulty: Medium
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Dutch National Flag Algorithm. Use three pointers: low for 0s, mid for 1s, and high for 2s.
- Evaluate nums[mid]. Swap and shrink boundaries depending on whether you hit a 0, 1, or 2.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
- Key Learnings:
- This is the definitive three-pointer algorithm for categorizing elements into three buckets in a single pass.
- We don't increment 'mid' when swapping with 'high' because the swapped element from 'high' is unexamined and could be a 0.
 *
- Status: Accepted
 */