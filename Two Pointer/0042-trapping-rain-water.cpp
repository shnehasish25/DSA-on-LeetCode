/*
- ============================================================
- Problem   : Trapping Rain Water
- LeetCode  : https://leetcode.com/problems/trapping-rain-water/
- Problem # : 42
- Difficulty: Hard
- Topic     : Array, Two Pointers, Dynamic Programming
 *
- Approach:
- Maintain two pointers at the ends of the array, and keep track of the maximum height seen so far from both the left and right.
- Move the pointer with the smaller max height inward, calculating trapped water based on its respective max height.
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
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int water_trapped = 0;
        
        while (left < right) {
            // 1. We always process the side with the smaller bounding wall
            if (height[left] < height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left]; // Update left boundary
                } else {
                    water_trapped += max_left - height[left]; // Calculate trapped water
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right]; // Update right boundary
                } else {
                    water_trapped += max_right - height[right]; // Calculate trapped water
                }
                right--;
            }
        }
        
        return water_trapped;
    }
};

/*
- Key Learnings:
- Water trapped above any block depends purely on min(max_left, max_right). By always moving the pointer with the smaller max, we guarantee the bottleneck is handled correctly.
- This two-pointer optimization brings space complexity down from O(n) (using prefix max arrays) to an elegant O(1).
 *
- Status: Accepted
 */