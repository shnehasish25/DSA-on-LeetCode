/*
- ============================================================
- Problem   : 3Sum Closest
- LeetCode  : https://leetcode.com/problems/3sum-closest/
- Problem # : 16
- Difficulty: Medium
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Sort the array first. Iterate through the array fixing one number.
- Use two pointers for the rest, tracking the minimum difference to the target to find the closest sum.
 *
- Time Complexity  : O(n^2)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                if (current_sum < target) left++;
                else if (current_sum > target) right--;
                else return current_sum;
            }
        }
        return closest_sum;
    }
};

/*
- Key Learnings:
- Identical setup to 3Sum, but instead of finding exact zero matches, we constantly update a variable tracking the minimum absolute difference.
- Sorting is the enabler for intelligently moving the left/right pointers.
 *
- Status: Accepted
 */