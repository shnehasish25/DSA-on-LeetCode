/*
- ============================================================
- Problem   : Merge Intervals
- LeetCode  : https://leetcode.com/problems/merge-intervals/
- Problem # : 56
- Difficulty: Medium
- Topic     : Array, Sorting
 *
- Approach:
- Sort the intervals based on their start times.
- Iterate through them: if the current interval's start is <= the previous interval's end, merge them by updating the end to the maximum of both.
- Otherwise, push the current interval to the result.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(n) or O(1) excluding output array depending on sort
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Sorting by start time is the universal first step for almost all interval problems.
- Always update the 'end' time with max() because the merged interval might completely engulf the next one.
 *
- Status: Accepted
 */