/*
- ============================================================
- Problem   : Remove Covered Intervals
- LeetCode  : https://leetcode.com/problems/remove-covered-intervals/
- Problem # : 1288
- Difficulty: Medium
- Topic     : Array, Sorting
 *
- Approach:
- Sort intervals by start time ascending. If start times are equal, sort by end time descending.
- This guarantees that a covered interval will immediately follow the interval that covers it.
- Iterate and count intervals whose end time is less than or equal to the maximum end time seen so far.
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int count = 0;
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            if (interval[1] <= max_end) {
                count++; // Covered
            } else {
                max_end = interval[1]; // Update bound
            }
        }
        
        return intervals.size() - count;
    }
};

/*
- Key Learnings:
- Sorting by end time descending when start times tie is the secret sauce here. It puts the largest enclosing interval first.
- We only need to track 'max_end' because the sorting handles the start time constraints for us.
 *
- Status: Accepted
 */