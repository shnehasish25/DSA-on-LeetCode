/*
- ============================================================
- Problem   : Meeting Rooms
- LeetCode  : https://leetcode.com/problems/meeting-rooms/
- Problem # : 252
- Difficulty: Easy
- Topic     : Array, Sorting
 *
- Approach:
- Sort the meetings by their start time.
- Iterate through the sorted meetings. If a meeting starts before the previous one ends, they overlap and a person cannot attend both.
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
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        
        sort(intervals.begin(), intervals.end());
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false; // Overlap detected
            }
        }
        
        return true;
    }
};

/*
- Key Learnings:
- A classic introduction to interval logic. Sorting the array instantly reveals structural collisions.
- Meetings ending at the exact same time the next one starts (e.g., [5,10] and [10,15]) do not count as an overlap, hence strictly '<'.
 *
- Status: Accepted
 */