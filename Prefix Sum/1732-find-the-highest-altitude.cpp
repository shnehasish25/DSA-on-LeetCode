/*
- ============================================================
- Problem   : Find the Highest Altitude
- LeetCode  : https://leetcode.com/problems/find-the-highest-altitude/
- Problem # : 1732
- Difficulty: Easy
- Topic     : Array, Prefix Sum
 *
- Approach:
- The altitude at any point is the prefix sum of all previous altitude gains.
- Maintain a running sum starting from 0, updating the maximum altitude observed.
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
    int largestAltitude(vector<int>& gain) {
        int current_alt = 0;
        int max_alt = 0;
        
        for (int g : gain) {
            current_alt += g;
            max_alt = max(max_alt, current_alt);
        }
        
        return max_alt;
    }
};

/*
- Key Learnings:
- Prefix sum is fundamentally about accumulation over time.
- Starting condition is 0, so the max altitude must initially be 0.
 *
- Status: Accepted
 */