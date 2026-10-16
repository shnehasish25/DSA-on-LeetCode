/*
- ============================================================
- Problem   : Backspace String Compare
- LeetCode  : https://leetcode.com/problems/backspace-string-compare/
- Problem # : 844
- Difficulty: Easy
- Topic     : String, Stack
 *
- Approach:
- Strings in C++ can act directly as a stack (using push_back and pop_back).
- Iterate through both strings: push standard characters, pop the last character on '#'. Compare the resulting strings.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
    string build(string& s) {
        string res = "";
        for (char c : s) {
            if (c != '#') {
                res.push_back(c);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};

/*
- Key Learnings:
- You don't always need to instantiate std::stack. A string or vector behaves exactly like a stack and provides the added benefit of O(1) string comparison at the end.
- (Note: an O(1) space Two Pointer approach exists, but this string/stack approach is vastly simpler and robust for interviews).
 *
- Status: Accepted
 */