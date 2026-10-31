/*
- ============================================================
- Problem   : Remove All Adjacent Duplicates In String
- LeetCode  : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
- Problem # : 1047
- Difficulty: Easy
- Topic     : String, Stack
 *
- Approach:
- Use a string as a stack.
- Iterate through the characters. If the current character matches the character at the back of the string, pop it.
- Otherwise, append the character.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        
        for (char c : s) {
            if (!res.empty() && res.back() == c) {
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
- The "string as a stack" pattern strikes again. It prevents the need to dump a std::stack into a string and reverse it at the very end.
- Instantly resolves cascading deletions (e.g., "abba" -> "aa" -> "").
 *
- Status: Accepted
 */