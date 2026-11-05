/*
- ============================================================
- Problem   : Sum of Subarray Ranges
- LeetCode  : https://leetcode.com/problems/sum-of-subarray-ranges/
- Problem # : 2104
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Range = Max - Min. Therefore, Sum of Ranges = (Sum of Subarray Maximums) - (Sum of Subarray Minimums).
- Run the O(N) Monotonic Stack logic twice: once to find all minimum contributions (LeetCode 907) and once to find maximum contributions.
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
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        // Sum of Minimums
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int curr = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                sum -= (long long)nums[curr] * (i - curr) * (curr - left);
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Sum of Maximums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int curr = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                sum += (long long)nums[curr] * (i - curr) * (curr - left);
            }
            st.push(i);
        }
        
        return sum;
    }
};

/*
- Key Learnings:
- Mathematical decoupling: Sum(Max - Min) = Sum(Max) - Sum(Min).
- Applying the "boundary pushing" technique (i == n) flushes the entire stack without needing secondary PLE/NLE arrays, saving immense space.
 *
- Status: Accepted
 */