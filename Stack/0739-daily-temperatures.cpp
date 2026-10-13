/*
- ============================================================
- Problem   : Daily Temperatures
- LeetCode  : https://leetcode.com/problems/daily-temperatures/
- Problem # : 739
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Use a Monotonic Decreasing Stack that stores the *indices* of the temperatures.
- If the current temperature is strictly warmer than the temperature at the index on the top of the stack, we found our answer for that top index. Pop it and calculate the index difference.
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st; // Stores indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_index = st.top();
                st.pop();
                res[prev_index] = i - prev_index;
            }
            st.push(i);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- This is the "Hello World" of Monotonic Stacks. 
- The stack holds unresolved queries (days waiting for a warmer temp). 
- Processing elements out of order requires storing *indices*, not values, so we can map results back to the correct original positions.
 *
- Status: Accepted
 */