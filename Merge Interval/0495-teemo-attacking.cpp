/*
- ============================================================
- Problem   : Teemo Attacking
- LeetCode  : https://leetcode.com/problems/teemo-attacking/
- Problem # : 495
- Difficulty: Easy
- Topic     : Array, Simulation
 *
- Approach:
- Iterate through the attack times. The duration of poison for a single attack is 'duration'.
- If the gap between the current attack and the next attack is less than 'duration', the poison time is capped by the gap.
- Otherwise, the full 'duration' applies.
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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int total_time = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            total_time += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        
        // Add the full duration for the very last attack
        total_time += duration;
        
        return total_time;
    }
};

/*
- Key Learnings:
- This is interval merging simplified. Because intervals are uniformly sized ('duration') and already sorted, we don't need a heavy merge function.
- The 'min' function perfectly handles the overlap condition instantly.
 *
- Status: Accepted
 */