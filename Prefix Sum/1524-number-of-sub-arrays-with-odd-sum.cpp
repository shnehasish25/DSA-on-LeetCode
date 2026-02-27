/*
- ============================================================
- Problem   : Number of Sub-arrays With Odd Sum
- LeetCode  : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
- Problem # : 1524
- Difficulty: Medium
- Topic     : Array, Math, Prefix Sum
 *
- Approach:
- Keep track of how many odd and even prefix sums have been seen so far.
- If the current prefix sum is odd, adding it to any previous even prefix sum yields an odd subarray. If even, add to previous odd prefixes.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int odd_count = 0, even_count = 1; // Base case: prefix sum of 0 is even
        int current_sum = 0, result = 0;
        
        for (int num : arr) {
            current_sum += num;
            
            if (current_sum % 2 != 0) {
                result = (result + even_count) % mod;
                odd_count++;
            } else {
                result = (result + odd_count) % mod;
                even_count++;
            }
        }
        
        return result;
    }
};

/*
- Key Learnings:
- Odd - Even = Odd, and Even - Odd = Odd. 
- You do not need to store the prefix sums themselves, just the running tally of their parities.
 *
- Status: Accepted
 */