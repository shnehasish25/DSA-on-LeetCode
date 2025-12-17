/*
- ============================================================
- Problem   : Minimum Number of Arrows to Burst Balloons
- LeetCode  : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
- Problem # : 452
- Difficulty: Medium
- Topic     : Array, Greedy, Sorting
 *
- Approach:
- Sort balloons by their END coordinates.
- Shoot the first arrow at the end of the first balloon. If the next balloon starts after the current arrow position, we need a new arrow.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(1) or O(log n) for sorting
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int current_end = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            // If the balloon starts strictly after the arrow position, we need a new arrow
            if (points[i][0] > current_end) {
                arrows++;
                current_end = points[i][1];
            }
        }
        
        return arrows;
    }
};

/*
- Key Learnings:
- Mechanically identical to "Non-overlapping Intervals". Overlapping intervals can be destroyed by a single arrow.
- Always watch out for integer overflow if subtracting coordinates during custom sorting. Using < is safer than a - b.
 *
- Status: Accepted
 */