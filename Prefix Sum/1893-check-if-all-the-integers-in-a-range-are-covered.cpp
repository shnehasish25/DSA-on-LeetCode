/*
- ============================================================
- Problem   : Check if All the Integers in a Range Are Covered
- LeetCode  : https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
- Problem # : 1893
- Difficulty: Easy
- Topic     : Array, Hash Table, Prefix Sum
 *
- Approach:
- Use a Difference Array for the range [1, 51]. Apply +1 at the start of a range and -1 just past the end of the range.
- Run a prefix sum to calculate how many overlapping intervals cover each integer.
- Finally, verify that every integer from 'left' to 'right' has a coverage > 0.
 *
- Time Complexity  : O(n + 50)
- Space Complexity : O(50) -> O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        
        for (const auto& r : ranges) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }
        
        int coverage = 0;
        for (int i = 1; i <= 50; i++) {
            coverage += diff[i];
            if (i >= left && i <= right && coverage == 0) {
                return false;
            }
        }
        
        return true;
    }
};

/*
- Key Learnings:
- The Difference Array (Line Sweep) is the optimal method for resolving mass interval coverage queries.
- Hard constraints (values up to 50) allow us to use a constant-sized tracking array for an O(1) space solution.
 *
- Status: Accepted
 */