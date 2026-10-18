/*
- ============================================================
- Problem   : Sum of Subarray Minimums
- LeetCode  : https://leetcode.com/problems/sum-of-subarray-minimums/
- Problem # : 907
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Every element is the minimum for exactly (Left Expansion * Right Expansion) subarrays.
- Use a Monotonic Increasing stack to find the Previous Less Element (PLE) and Next Less Element (NLE).
- Calculate contribution of nums[i]: (i - PLE[i]) * (NLE[i] - i) * nums[i]. Sum them up.
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        
        // Find Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Find Next Less Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long combos = (long long)left[i] * right[i];
            sum = (sum + combos * arr[i]) % mod;
        }
        
        return sum;
    }
};

/*
- Key Learnings:
- The "PLE/NLE" pattern completely eliminates enumerating subarrays. 
- Using >= on one side and strictly > on the other gracefully handles duplicate numbers, preventing identical subarrays from being double-counted.
 *
- Status: Accepted
 */