/*
- ============================================================
- Problem   : Make Sum Divisible by P
- LeetCode  : https://leetcode.com/problems/make-sum-divisible-by-p/
- Problem # : 1590
- Difficulty: Medium
- Topic     : Array, Hash Table, Prefix Sum
 *
- Approach:
- Calculate total sum modulo p. This is the target remainder we must remove via a contiguous subarray.
- Use a hash map to track the most recent index of each prefix sum modulo p, searching for the complement that completes the target removal.
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
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) total_sum += num;
        
        int target = total_sum % p;
        if (target == 0) return 0;
        
        unordered_map<int, int> last_seen;
        last_seen[0] = -1;
        
        int current_sum = 0, min_len = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum = (current_sum + nums[i]) % p;
            
            int needed = (current_sum - target + p) % p;
            if (last_seen.find(needed) != last_seen.end()) {
                min_len = min(min_len, i - last_seen[needed]);
            }
            
            last_seen[current_sum] = i;
        }
        
        return min_len == nums.size() ? -1 : min_len;
    }
};

/*
- Key Learnings:
- This is a masterclass combination of "Subarray Sum Equals K" and Modular Arithmetic.
- Modulo math in C++ requires adding 'p' before the final modulo to handle negative wrap-arounds safely: (curr - target + p) % p.
 *
- Status: Accepted
 */