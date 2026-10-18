/*
- ============================================================
- Problem   : Car Fleet
- LeetCode  : https://leetcode.com/problems/car-fleet/
- Problem # : 853
- Difficulty: Medium
- Topic     : Array, Stack, Sorting
 *
- Approach:
- Combine position and speed into pairs, and sort descending by position (closest to target first).
- Calculate the time it takes for each car to reach the target: (target - position) / speed.
- If a car takes longer than the fleet ahead of it, it becomes a new fleet bottleneck. Track these bottlenecks.
 *
- Time Complexity  : O(n log n) for sorting
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Sort cars descending by position (closest to target first)
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());
        
        int fleets = 0;
        double max_time = 0.0; // Time of the slowest car ahead
        
        for (const auto& car : cars) {
            // If this car needs strictly more time, it cannot catch up. Forms a new fleet.
            if (car.second > max_time) {
                max_time = car.second;
                fleets++;
            }
        }
        
        return fleets;
    }
};

/*
- Key Learnings:
- Sometimes a Stack can be optimized down to a single state variable. We only care about the bottleneck time of the fleet currently ahead of us ('max_time').
- Sorting in descending order processes the "leader" cars first, which govern the speed of anyone behind them.
 *
- Status: Accepted
 */