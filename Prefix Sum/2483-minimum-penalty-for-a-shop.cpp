/*
- ============================================================
- Problem   : Minimum Penalty for a Shop
- LeetCode  : https://leetcode.com/problems/minimum-penalty-for-a-shop/
- Problem # : 2483
- Difficulty: Medium
- Topic     : String, Prefix Sum
 *
- Approach:
- Closing the shop at hour 'i' costs +1 for every 'Y' after 'i' and +1 for every 'N' before 'i'.
- Iterate once keeping a relative score. A 'Y' means we should have stayed open (score--), an 'N' means we should close (score++).
- The minimum running score reveals the absolute best hour to close.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int current_penalty = 0, min_penalty = 0;
        int best_hour = 0;
        
        for (int i = 0; i < customers.length(); i++) {
            if (customers[i] == 'Y') {
                current_penalty--; // Staying open would have been better
            } else {
                current_penalty++; // Closing would have been better
            }
            
            if (current_penalty < min_penalty) {
                min_penalty = current_penalty;
                best_hour = i + 1; // Update best hour to close just AFTER this customer
            }
        }
        
        return best_hour;
    }
};

/*
- Key Learnings:
- Instead of computing absolute penalties (requiring two passes), tracking the relative change in penalty in a single pass gives the identical inflection point.
- Elegant state logic: dropping the score below the minimum implies moving the closing time forward was a net positive.
 *
- Status: Accepted
 */