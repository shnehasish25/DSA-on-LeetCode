/*
- ============================================================
- Problem   : Remove K Digits
- LeetCode  : https://leetcode.com/problems/remove-k-digits/
- Problem # : 402
- Difficulty: Medium
- Topic     : String, Stack, Monotonic Stack, Greedy
 *
- Approach:
- A smaller number is formed by having smaller digits at the most significant positions.
- Use a monotonic increasing stack. If the current digit is smaller than the stack top and we still have 'k' deletions left, pop the top.
- Trim leading zeroes. If 'k' remains at the end, drop the tail elements.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        
        for (char c : num) {
            while (!st.empty() && st.back() > c && k > 0) {
                st.pop_back();
                k--;
            }
            if (!st.empty() || c != '0') { // Prevent leading zeroes
                st.push_back(c);
            }
        }
        
        while (!st.empty() && k > 0) { // If 'k' still remains (e.g., already sorted sequence "1234")
            st.pop_back();
            k--;
        }
        
        return st.empty() ? "0" : st;
    }
};

/*
- Key Learnings:
- The peak of the graph is always the optimal digit to delete to minimize a number.
- String as a stack is vastly superior here as returning the final answer requires zero conversion overhead.
 *
- Status: Accepted
 */