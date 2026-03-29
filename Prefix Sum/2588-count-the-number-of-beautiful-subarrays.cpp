/*
- ============================================================
- Problem   : Count the Number of Beautiful Subarrays
- LeetCode  : https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/
- Problem # : 2588
- Difficulty: Medium
- Topic     : Array, Hash Table, Bit Manipulation, Prefix Sum
 *
- Approach:
- "Removing a set bit from both elements" effectively means finding subarrays where the total XOR sum is exactly 0.
- Track frequencies of Prefix XORs in a Hash Map. If a Prefix XOR has been seen before, the subarray between them XORs to 0.
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
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        
        long long count = 0;
        int current_xor = 0;
        
        for (int num : nums) {
            current_xor ^= num;
            
            if (prefix_counts.count(current_xor)) {
                count += prefix_counts[current_xor];
            }
            
            prefix_counts[current_xor]++;
        }
        
        return count;
    }
};

/*
- Key Learnings:
- The complex bit manipulation requirement mathematically reduces to: "Find subarrays with XOR sum == 0".
- Mechanically identical to "Subarray Sum Equals K" (LeetCode 560), replacing addition with XOR and K with 0.
 *
- Status: Accepted
 */