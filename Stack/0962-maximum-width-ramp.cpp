/*
- ============================================================
- Problem   : Maximum Width Ramp
- LeetCode  : https://leetcode.com/problems/maximum-width-ramp/
- Problem # : 962
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Build a strictly decreasing monotonic stack of indices from left to right.
- Iterate from right to left. If nums[i] >= nums[st.top()], pop the stack and calculate width, updating max width.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        
        int max_width = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                max_width = max(max_width, i - st.top());
                st.pop();
            }
        }
        
        return max_width;
    }
};

/*
- Key Learnings:
- A strictly decreasing stack records all possible "best left bounds". 
- Traversing right-to-left guarantees that when we pop, we are securing the absolute maximum possible width for that specific left bound.
 *
- Status: Accepted
 */