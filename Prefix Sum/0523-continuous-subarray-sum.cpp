/*
- ============================================================
- Problem   : Continuous Subarray Sum
- LeetCode  : https://leetcode.com/problems/continuous-subarray-sum/
- Problem # : 523
- Difficulty: Medium
- Topic     : Array, Hash Table, Prefix Sum, Math
 *
- Approach:
- Compute the running prefix sum modulo k. 
- If the same remainder is seen again, it means the subarray sum between those indices is a multiple of k.
 *
- Time Complexity  : O(n)
- Space Complexity : O(min(n, k))
- ============================================================
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_index;
        remainder_index[0] = -1; 
        
        int current_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            int remainder = current_sum % k;
            
            // Handle negative remainders just in case (though nums are >= 0 here)
            if (remainder < 0) remainder += k;
            
            if (remainder_index.find(remainder) != remainder_index.end()) {
                if (i - remainder_index[remainder] > 1) { // Length must be at least 2
                    return true;
                }
            } else {
                remainder_index[remainder] = i;
            }
        }
        
        return false;
    }
};

/*
- Key Learnings:
- Prefix Sum + Modulo math is a heavy-hitting combination. If Prefix_Sum[i] % k == Prefix_Sum[j] % k, then the difference is a multiple of k.
- We must enforce length >= 2 by checking 'i - previous_index > 1'.
 *
- Status: Accepted
 */