/*
- ============================================================
- Problem   : Insert Interval
- LeetCode  : https://leetcode.com/problems/insert-interval/
- Problem # : 57
- Difficulty: Medium
- Topic     : Array
 *
- Approach:
- Iterate through the intervals. If the current interval ends before the new one begins, push the current interval.
- If it overlaps, merge them into the new interval by taking the min start and max end.
- Once we pass the new interval, push the new interval and the rest of the array.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n) for the result array
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        
        // 1. Skip all intervals that come completely before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        // 2. Merge all overlapping intervals into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        // 3. Add all the remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Since the input is already sorted, we don't need O(n log n) sorting. We can do this in a single O(n) pass.
- Using a 3-step 'while' loop approach cleanly separates the before, during, and after phases of insertion.
 *
- Status: Accepted
 */