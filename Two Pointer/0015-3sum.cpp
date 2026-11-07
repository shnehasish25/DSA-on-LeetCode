/*
- ============================================================
- Problem   : 3Sum
- LeetCode  : https://leetcode.com/problems/3sum/
- Problem # : 15
- Difficulty: Medium
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Sort the array first to make duplicate handling and two-pointer traversal easy.
- Iterate through the array, fixing one number, and use two pointers (left and right) on the remaining array to find pairs that sum to -fixed_number.
 *
- Time Complexity  : O(n^2)
- Space Complexity : O(1) or O(n) depending on sorting algorithm memory
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 1. Sorting is crucial for two pointers
        
        for (int i = 0; i < nums.size(); i++) {
            // 2. Skip duplicates for the fixed number to prevent duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    // 3. Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    
                    // 4. Skip duplicates for the left pointer to avoid identical results
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        
        return result;
    }
};

/*
- Key Learnings:
- Sorting the array is the hidden trick to efficiently handling duplicate triplets without needing an expensive Hash Set.
- 3Sum is essentially a loop wrapped around a standard Two Sum II (sorted array) implementation.
 *
- Status: Accepted
 */