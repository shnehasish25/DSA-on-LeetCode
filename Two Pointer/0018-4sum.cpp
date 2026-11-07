/*
- ============================================================
- Problem   : 4Sum
- LeetCode  : https://leetcode.com/problems/4sum/
- Problem # : 18
- Difficulty: Medium
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Sort the array. Use two nested loops to fix the first two numbers.
- Apply standard two-pointer logic for the remaining two numbers, skipping duplicates at every level.
 *
- Time Complexity  : O(n^3)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

/*
- Key Learnings:
- K-Sum problems generally reduce to (K-2) nested loops wrapping a Two Sum II approach.
- Type casting to long long is required when adding four potentially large integers to prevent overflow.
 *
- Status: Accepted
 */