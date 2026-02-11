/*
- ============================================================
- Problem   : Subarray Sum Equals K
- LeetCode  : https://leetcode.com/problems/subarray-sum-equals-k/
- Problem # : 560
- Difficulty: Medium
- Topic     : Array, Hash Table, Prefix Sum
 *
- Approach:
- Use a hash map to store the frequencies of prefix sums seen so far.
- If (current_prefix_sum - k) exists in the map, it means there is a contiguous subarray ending here that sums to k.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1; // Base case for subarray starting at index 0
        
        int current_sum = 0, count = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            if (prefix_counts.find(current_sum - k) != prefix_counts.end()) {
                count += prefix_counts[current_sum - k];
            }
            
            prefix_counts[current_sum]++;
        }
        
        return count;
    }
};

/*
- Key Learnings:
- This is the single most important Prefix Sum problem on LeetCode. It combines Prefix Sum with Two Sum hash map logic.
- Initializing map[0] = 1 is essential to catch subarrays that naturally sum to k right from the very first index.
 *
- Status: Accepted
 */