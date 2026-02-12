/*
- ============================================================
- Problem   : Corporate Flight Bookings
- LeetCode  : https://leetcode.com/problems/corporate-flight-bookings/
- Problem # : 1109
- Difficulty: Medium
- Topic     : Array, Prefix Sum
 *
- Approach:
- Use the Difference Array technique (Line Sweep).
- For a booking [first, last, seats], add seats to 'first' and subtract seats from 'last + 1'.
- Run a standard prefix sum over the array to get the total active seats at any given flight.
 *
- Time Complexity  : O(n + m) where m is number of bookings
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        
        for (const auto& b : bookings) {
            int first = b[0] - 1;
            int last = b[1] - 1;
            int seats = b[2];
            
            res[first] += seats;
            if (last + 1 < n) {
                res[last + 1] -= seats;
            }
        }
        
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Applying +val at the start index and -val at the (end + 1) index allows O(1) range updates.
- The final running sum effortlessly cascades those changes across the entire array.
 *
- Status: Accepted
 */