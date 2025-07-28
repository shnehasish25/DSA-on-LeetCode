/*
- ============================================================
- Problem   : Find the Substring With Maximum Cost
- LeetCode  : https://leetcode.com/problems/find-the-substring-with-maximum-cost/
- Problem # : 2606
- Difficulty: Medium
- Topic     : String, Dynamic Programming, Array
 *
- Approach:
- Create a cost map array of size 26 mapping each character to its respective cost (or base 1 to 26 cost).
- Convert the string into an array of integers, then simply apply standard Kadane's Algorithm.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (size 26 array)
- ============================================================
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26);
        for (int i = 0; i < 26; i++) {
            cost[i] = i + 1;
        }
        for (int i = 0; i < chars.length(); i++) {
            cost[chars[i] - 'a'] = vals[i];
        }
        
        int max_cost = 0, current_cost = 0;
        
        for (char c : s) {
            int val = cost[c - 'a'];
            current_cost = max(val, current_cost + val);
            max_cost = max(max_cost, current_cost);
        }
        
        return max_cost;
    }
};

/*
- Key Learnings:
- Data mapping is a critical preprocessing step. Once the characters are transformed into integers, it is exactly LeetCode #53.
- The empty string condition mandates that max_cost initializes to 0.
 *
- Status: Accepted
 */