/*
- ============================================================
- Problem   : Maximum Score After Splitting a String
- LeetCode  : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
- Problem # : 1422
- Difficulty: Easy
- Topic     : String, Prefix Sum
 *
- Approach:
- Count all the 1s in the string first to establish a right suffix sum.
- Iterate through the string (up to n-1), tracking zeroes on the left. Deduct 1s from the right as you encounter them.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int right_ones = 0;
        for (char c : s) {
            if (c == '1') right_ones++;
        }
        
        int left_zeroes = 0;
        int max_score = 0;
        
        // Loop up to s.length() - 1 because both halves must be non-empty
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                left_zeroes++;
            } else {
                right_ones--;
            }
            max_score = max(max_score, left_zeroes + right_ones);
        }
        
        return max_score;
    }
};

/*
- Key Learnings:
- Precomputing a global sum allows us to avoid building dual prefix arrays (one for 0s left, one for 1s right).
- Splitting strings into two non-empty halves implies the loop strictly ends at length - 1.
 *
- Status: Accepted
 */