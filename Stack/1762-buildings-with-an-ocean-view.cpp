/*
- ============================================================
- Problem   : Buildings With an Ocean View (Premium)
- LeetCode  : https://leetcode.com/problems/buildings-with-an-ocean-view/
- Problem # : 1762
- Difficulty: Medium
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Use a monotonic decreasing stack tracking indices.
- Iterate left to right. If a building is taller than or equal to the building at the index on the stack top, it blocks its view. Pop it.
- After processing all buildings, the remaining indices in the stack represent the strictly visible buildings.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> st; // Acts as the monotonic decreasing stack
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] <= heights[i]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        
        return st;
    }
};

/*
- Key Learnings:
- Monotonic stacks natively filter visual blockage limits perfectly.
- A right-to-left O(1) space traversal is technically possible, but the Left-to-Right stack naturally outputs the indices in the requested sorted ascending order.
 *
- Status: Accepted
 */