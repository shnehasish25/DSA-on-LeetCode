/*
- ============================================================
- Problem   : Contiguous Array
- LeetCode  : https://leetcode.com/problems/contiguous-array/
- Problem # : 525
- Difficulty: Medium
- Topic     : Array, Hash Table, Prefix Sum
 *
- Approach:
- Treat 0s as -1s and 1s as +1s. The problem reduces to finding the longest subarray with a sum of 0.
- Use a hash map to store the first time a prefix sum is seen. If it's seen again, the subarray between those indices sums to 0.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix_index;
        prefix_index[0] = -1; // Base case
        
        int current_sum = 0, max_len = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum += (nums[i] == 0) ? -1 : 1;
            
            if (prefix_index.find(current_sum) != prefix_index.end()) {
                max_len = max(max_len, i - prefix_index[current_sum]);
            } else {
                prefix_index[current_sum] = i; // Store only the FIRST occurrence to maximize length
            }
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- Transforming 0s to -1s perfectly balances the array, mapping a binary constraint into a pure summation problem.
- Unlike 560 where we store frequencies, here we store the earliest index to maximize the subarray length.
 *
- Status: Accepted
 */