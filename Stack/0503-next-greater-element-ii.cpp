/*
- ============================================================
- Problem   : Next Greater Element II
- LeetCode  : https://leetcode.com/problems/next-greater-element-ii/
- Problem # : 503
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Since the array is circular, simulate a double-length array by looping 2 * n times and using the modulo operator (i % n).
- Run the standard Monotonic Stack logic to find the next greater elements.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // Stores indices
        
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!st.empty() && nums[idx] > nums[st.top()]) {
                res[st.top()] = nums[idx];
                st.pop();
            }
            // Only push indices during the first pass to avoid processing duplicates
            if (i < n) {
                st.push(idx);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Simulating circular arrays is almost always done by iterating up to (2 * n) and indexing via (i % n).
- Pushing to the stack only during the first pass (i < n) is a critical optimization so the stack doesn't grow unnecessarily.
 *
- Status: Accepted
 */