/*
- ============================================================
- Problem   : Container With Most Water
- LeetCode  : https://leetcode.com/problems/container-with-most-water/
- Problem # : 11
- Difficulty: Medium
- Topic     : Array, Two Pointers, Greedy
 *
- Approach:
- Place two pointers at the ends of the array. The area is bounded by the shorter line.
- Calculate the area, then move the pointer pointing to the shorter line inward to potentially find a taller boundary.
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
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // 1. Calculate the current area bounded by the shorter line
            int current_height = min(height[left], height[right]);
            int width = right - left;
            int area = current_height * width;
            
            // 2. Update maximum area found so far
            max_area = max(max_area, area);
            
            // 3. Move the pointer of the shorter line inward to seek a taller line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

/*
- Key Learnings:
- Moving the taller line inward can never increase the area, because the width strictly decreases. Always move the shorter line.
- This is a classic greedy two-pointer strategy where we make the locally optimal choice at each step to find the global optimum.
 *
- Status: Accepted
 */