/*
- ============================================================
- Problem   : Number of Substrings Containing All Three Characters
- LeetCode  : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
- Problem # : 1358
- Difficulty: Medium
- Topic     : String, Sliding Window
 *
- Approach:
- Keep track of the last seen index for 'a', 'b', and 'c'.
- At any character, the number of valid substrings ending at this character is bounded by the minimum of the three last seen indices + 1.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen = {-1, -1, -1};
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            last_seen[s[i] - 'a'] = i;
            
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                count += (1 + min({last_seen[0], last_seen[1], last_seen[2]}));
            }
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Instead of using a standard left/right sliding window, tracking the trailing "bottleneck" index calculates combinations instantly.
- The "+1" accounts for the substring starting from index 0 up to the minimum index.
 *
- Status: Accepted
 */