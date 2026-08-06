/*
- ============================================================
- Problem   : Trapping Rain Water (Stack Approach)
- LeetCode  : https://leetcode.com/problems/trapping-rain-water/
- Problem # : 42
- Difficulty: Hard
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- Use a strictly monotonic decreasing stack to store indices of the bars.
- When you encounter a bar higher than the stack's top, a basin is formed.
- Pop the bottom of the basin, check the new top (left wall), and calculate the trapped water horizontally layer by layer.
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
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int basin = st.top();
                st.pop();
                
                if (st.empty()) break; // No left wall to bound the water
                
                int left_wall = st.top();
                int width = i - left_wall - 1;
                int bounded_height = min(height[i], height[left_wall]) - height[basin];
                
                water += width * bounded_height;
            }
            st.push(i);
        }
        
        return water;
    }
};

/*
- Key Learnings:
- Unlike the Two Pointer approach (vertical columns of water), the Stack approach calculates water horizontally in bounded rectangles.
- The while loop dynamically resolves cascading, stepped basins perfectly.
 *
- Status: Accepted
 */