/*
- ============================================================
- Problem   : Shifting Letters II
- LeetCode  : https://leetcode.com/problems/shifting-letters-ii/
- Problem # : 2381
- Difficulty: Medium
- Topic     : Array, String, Prefix Sum
 *
- Approach:
- Apply Difference Array technique to track net shifts (+1 for forward, -1 for backward).
- Calculate the prefix sum to get the total shifts for each character, normalize it to positive modulo 26, and apply it.
 *
- Time Complexity  : O(n + q) where q is number of shifts
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], dir = shift[2];
            int val = (dir == 1) ? 1 : -1;
            
            diff[start] += val;
            diff[end + 1] -= val;
        }
        
        int current_shift = 0;
        for (int i = 0; i < n; i++) {
            current_shift += diff[i];
            
            // Normalize shift to handle negative values and large numbers safely
            int net_shift = (current_shift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        
        return s;
    }
};

/*
- Key Learnings:
- Shifting characters requires resolving all range overlaps first using a Difference Array.
- C++ modulo of negative numbers produces a negative result. Standardize it by doing ((x % 26) + 26) % 26.
 *
- Status: Accepted
 */