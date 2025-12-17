/*
- ============================================================
- Problem   : Meeting Rooms II
- LeetCode  : https://leetcode.com/problems/meeting-rooms-ii/
- Problem # : 253
- Difficulty: Medium
- Topic     : Array, Two Pointers, Sorting, Greedy
 *
- Approach:
- Separate the start times and end times into two distinct arrays and sort them independently.
- Use two pointers. If a start time is earlier than the current end time, a new room is needed.
- If it's greater or equal, a room frees up (increment end pointer).
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        vector<int> starts, ends;
        for (const auto& i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int rooms = 0, max_rooms = 0;
        int s = 0, e = 0;
        
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                rooms++; // Meeting started, room occupied
                s++;
            } else {
                rooms--; // Meeting ended, room freed
                e++;
            }
            max_rooms = max(max_rooms, rooms);
        }
        
        return max_rooms;
    }
};

/*
- Key Learnings:
- Decoupling starts and ends is a brilliant chronological trick. We don't care WHICH meeting ended, just that SOME meeting ended and freed a room.
- This simulates the Line Sweep / Difference Array logic but uses sorting and Two Pointers to handle continuous time.
 *
- Status: Accepted
 */