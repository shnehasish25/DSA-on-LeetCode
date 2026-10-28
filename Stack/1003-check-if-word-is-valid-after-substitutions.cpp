/*
- ============================================================
- Problem   : Check If Word Is Valid After Substitutions
- LeetCode  : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
- Problem # : 1003
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Use a string as a stack.
- Push characters one by one. If the string ends with "abc", immediately pop the last 3 characters.
- If the original string was valid, the stack will be completely empty at the end.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string st = "";
        
        for (char c : s) {
            st.push_back(c);
            
            if (st.size() >= 3 && st.substr(st.size() - 3) == "abc") {
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
        }
        
        return st.empty();
    }
};

/*
- Key Learnings:
- This is the string pattern matching equivalent of "Valid Parentheses".
- Deleting substrings iteratively using a stack instantly resolves recursive nesting (e.g., "aabcbc" -> "abc" -> "").
 *
- Status: Accepted
 */