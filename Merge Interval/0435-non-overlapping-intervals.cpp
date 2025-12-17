/*
- ============================================================
- Problem   : Non-overlapping Intervals
- LeetCode  : https://leetcode.com/problems/non-overlapping-intervals/
- Problem # : 435
- Difficulty: Medium
- Topic     : Array, Dynamic Programming, Greedy, Sorting
 *
- Approach:
- Sort intervals based on their END times (Greedy approach).
- Iterate. If a new interval starts before the previous one ends, it overlaps and must be removed (increment count).
- Otherwise, update the previous end to the current interval's end.
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int prev_end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev_end) {
                count++;
            } else {
                prev_end = intervals[i][1];
            }
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Sorting by END time instead of start time is the trick. It greedily leaves the maximum possible space for future intervals.
- C++ custom lambdas are perfect for sorting 2D vectors by specific columns.
 *
- Status: Accepted
 */