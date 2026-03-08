/*
- ============================================================
- Problem   : Sum of All Odd Length Subarrays
- LeetCode  : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
- Problem # : 1588
- Difficulty: Easy
- Topic     : Array, Prefix Sum, Math
 *
- Approach:
- Use prefix sum to quickly compute ranges in O(1) time within a nested loop generating odd lengths.
- (Alternative O(N) math approach exists, but Prefix Sum cleanly handles the subarray queries).
 *
- Time Complexity  : O(n^2)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            for (int len = 1; i + len <= n; len += 2) {
                total_sum += prefix[i + len] - prefix[i];
            }
        }
        
        return total_sum;
    }
};

/*
- Key Learnings:
- While O(n^3) brute force works for small sizes, building a prefix sum reduces calculating each subarray to an O(1) subtraction.
- Generating exact length jumps (len += 2) prevents doing manual parity checks.
 *
- Status: Accepted
 */