/*
- ============================================================
- Problem   : Make The String Great
- LeetCode  : https://leetcode.com/problems/make-the-string-great/
- Problem # : 1544
- Difficulty: Easy
- Topic     : String, Stack
 *
- Approach:
- Use a string as a stack.
- Two characters make a "bad pair" if their ASCII absolute difference is exactly 32 (e.g., 'A' vs 'a').
- If a bad pair is detected with the top of the stack, pop. Else, push.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res = "";
        
        for (char c : s) {
            if (!res.empty() && abs(res.back() - c) == 32) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The ASCII distance between any uppercase character and its exact lowercase counterpart is universally 32. 
- The cascading nature of destruction (like candy crush) makes it identical to "Remove All Adjacent Duplicates".
 *
- Status: Accepted
 */