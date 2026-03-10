/*
- ============================================================
- Problem   : Plates Between Candles
- LeetCode  : https://leetcode.com/problems/plates-between-candles/
- Problem # : 2055
- Difficulty: Medium
- Topic     : String, Binary Search, Prefix Sum
 *
- Approach:
- Use prefix sum to count plates (*). Track the nearest right candle index for any position, and the nearest left candle index.
- For query [L, R], snap L to its closest right candle, and R to its closest left candle, then subtract their plate prefix sums.
 *
- Time Complexity  : O(n + q)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefix(n + 1, 0);
        vector<int> left_candle(n, -1);
        vector<int> right_candle(n, -1);
        
        int plates = 0;
        int last_candle = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') plates++;
            else last_candle = i;
            
            prefix[i + 1] = plates;
            left_candle[i] = last_candle;
        }
        
        last_candle = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') last_candle = i;
            right_candle[i] = last_candle;
        }
        
        vector<int> res;
        for (const auto& q : queries) {
            int L = right_candle[q[0]];
            int R = left_candle[q[1]];
            
            if (L != -1 && R != -1 && L < R) {
                res.push_back(prefix[R + 1] - prefix[L]);
            } else {
                res.push_back(0);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Prefix sum solves the "how many" part, but left/right bounding arrays solve the "are they enclosed" part in O(1) time.
- Snapping boundaries inward to nearest valid anchors completely eliminates binary search constraints.
 *
- Status: Accepted
 */