/*
- ============================================================
- Problem   : 132 Pattern
- LeetCode  : https://leetcode.com/problems/132-pattern/
- Problem # : 456
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- We need i < j < k such that nums[i] < nums[k] < nums[j].
- Iterate backwards. Maintain a stack of potential 'nums[k]' (the '2' in 1-3-2).
- Track the maximum validated 'nums[k]' seen so far (the variable 'third').
- If we find an element smaller than 'third', it represents 'nums[i]' and the pattern is verified!
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        stack<int> st; // Stores potential '3's that are larger than '2's
        int third = INT_MIN; // The '2' in the 132 pattern
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) return true; // We found the '1'
            
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};

/*
- Key Learnings:
- Iterating backwards with a monotonic decreasing stack is the ideal way to search for "greater than trailing elements" structures.
- The 'third' variable acts as an anchor memory, caching the best (largest) valid trailing value.
 *
- Status: Accepted
 */