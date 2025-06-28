/*
- ============================================================
- Problem   : Maximum Subarray Sum with One Deletion
- LeetCode  : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
- Problem # : 1186
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- Maintain two states simultaneously: the max sum ending at 'i' with NO deletions, and the max sum ending at 'i' WITH exactly one deletion.
- The "one deletion" state can either extend a previous deleted state, or delete the current element from the previous non-deleted state.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int no_del = arr[0];
        int one_del = 0;
        int max_sum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            // Delete current element OR extend previous deletion
            one_del = max(no_del, one_del + arr[i]);
            // Standard Kadane
            no_del = max(arr[i], no_del + arr[i]);
            
            max_sum = max({max_sum, no_del, one_del});
        }
        
        return max_sum;
    }
};

/*
- Key Learnings:
- This is a masterclass in dynamic programming state machine logic.
- We don't need O(N) space arrays (prefix and suffix sums) because we only need the result from the immediate previous step.
 *
- Status: Accepted
 */