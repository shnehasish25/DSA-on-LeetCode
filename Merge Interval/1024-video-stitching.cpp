/*
- ============================================================
- Problem   : Video Stitching
- LeetCode  : https://leetcode.com/problems/video-stitching/
- Problem # : 1024
- Difficulty: Medium
- Topic     : Array, Dynamic Programming, Greedy
 *
- Approach:
- Sort clips by start time.
- Use a greedy approach: always pick the clip that starts before or at the current 'stitched' end time, but extends the furthest into the future.
- Update the 'stitched' end time and count. If we reach or exceed 'time', return the count.
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
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int count = 0, current_end = 0, next_end = 0;
        int i = 0, n = clips.size();
        
        while (current_end < time) {
            while (i < n && clips[i][0] <= current_end) {
                next_end = max(next_end, clips[i][1]);
                i++;
            }
            
            if (current_end == next_end) return -1; // Cannot extend further
            
            current_end = next_end;
            count++;
        }
        
        return count;
    }
};

/*
- Key Learnings:
- This is the exact same logic as "Jump Game II", applied to intervals.
- The inner while loop explores all valid candidates for the next 'jump' and greedily saves the one that goes the furthest.
 *
- Status: Accepted
 */