/*
- ============================================================
- Problem   : Car Pooling
- LeetCode  : https://leetcode.com/problems/car-pooling/
- Problem # : 1094
- Difficulty: Medium
- Topic     : Array, Sorting, Prefix Sum
 *
- Approach:
- Utilize a Difference Array for the timeline of 1001 locations.
- Add passengers at the start location, subtract at the end location. Accumulate to check if capacity is breached.
 *
- Time Complexity  : O(n + m) where m is max location (1001)
- Space Complexity : O(m)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timeline(1001, 0);
        
        for (const auto& t : trips) {
            int num_passengers = t[0];
            int start_loc = t[1];
            int end_loc = t[2];
            
            timeline[start_loc] += num_passengers;
            timeline[end_loc] -= num_passengers;
        }
        
        int current_capacity = 0;
        for (int i = 0; i <= 1000; i++) {
            current_capacity += timeline[i];
            if (current_capacity > capacity) {
                return false;
            }
        }
        
        return true;
    }
};

/*
- Key Learnings:
- Difference arrays completely eliminate the need for interval sorting and complex priority queues.
- Subtracting at 'end_loc' exactly mirrors the real-world logic of passengers getting out of the car.
 *
- Status: Accepted
 */