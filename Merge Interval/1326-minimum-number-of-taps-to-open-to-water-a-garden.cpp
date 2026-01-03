/*
- ============================================================
- Problem   : Minimum Number of Taps to Open to Water a Garden
- LeetCode  : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
- Problem # : 1326
- Difficulty: Hard
- Topic     : Array, Dynamic Programming, Greedy
 *
- Approach:
- Convert the taps into valid jump intervals: from max(0, i - ranges[i]) to i + ranges[i].
- Use the Greedy "Jump Game II" logic. Track the furthest reach from all taps covering the current point, jump, and repeat.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_reach(n + 1, 0);
        
        // Build max reach array (Jump Game format)
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            max_reach[start] = max(max_reach[start], end);
        }
        
        int taps = 0, current_end = 0, next_end = 0;
        
        for (int i = 0; i < n; i++) {
            next_end = max(next_end, max_reach[i]);
            
            if (i == current_end) {
                taps++;
                current_end = next_end;
                if (current_end >= n) return taps;
            }
        }
        
        return current_end >= n ? taps : -1;
    }
};

/*
- Key Learnings:
- Transforming left/right interval radii into a 1D array of "furthest right reach from index i" converts an Interval problem into Jump Game II.
- It bypasses sorting entirely, making it an O(n) solution.
 *
- Status: Accepted
 */