/*
- ============================================================
- Problem   : Steps to Make Array Non-decreasing
- LeetCode  : https://leetcode.com/problems/steps-to-make-array-non-decreasing/
- Problem # : 2289
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Traverse backwards. Use a Monotonic Stack storing pairs of {value, steps_survived}.
- If the current element is larger than the stack top, it will eat it. The steps taken is max(current_steps + 1, steps_survived_by_eaten_element).
- Keep popping until a larger element is found, updating the maximum steps required to eat the sequence.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        int max_steps = 0;
        stack<pair<int, int>> st; // {value, steps to eliminate it}
        
        for (int i = n - 1; i >= 0; i--) {
            int steps = 0;
            while (!st.empty() && nums[i] > st.top().first) {
                steps = max(steps + 1, st.top().second);
                st.pop();
            }
            max_steps = max(max_steps, steps);
            st.push({nums[i], steps});
        }
        
        return max_steps;
    }
};

/*
- Key Learnings:
- The time it takes for an element to eat a chain of smaller elements depends on how long those smaller elements took to eat their own chains (max state inheritance).
- Monotonic stacks flawlessly merge array traversal with Dynamic Programming state tracking.
 *
- Status: Accepted
 */