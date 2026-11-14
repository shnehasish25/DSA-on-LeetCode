/*
- ============================================================
- Problem   : Sort Array By Parity
- LeetCode  : https://leetcode.com/problems/sort-array-by-parity/
- Problem # : 905
- Difficulty: Easy
- Topic     : Array, Two Pointers
 *
- Approach:
- Place pointers at both ends of the array.
- Move left pointer if it sees an even number, move right if it sees odd. When left sees odd and right sees even, swap them.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;
            } else if (nums[right] % 2 != 0) {
                right--;
            } else {
                swap(nums[left], nums[right]);
                left++; right--;
            }
        }
        return nums;
    }
};

/*
- Key Learnings:
- This is exactly the Lomuto/Hoare partition scheme used in QuickSort, but the pivot condition is modulo 2 rather than magnitude.
- Swapping out of place elements from extremes handles categorization faster than in-place shifting.
 *
- Status: Accepted
 */