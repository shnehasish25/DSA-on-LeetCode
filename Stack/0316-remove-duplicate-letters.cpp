/*
- ============================================================
- Problem   : Remove Duplicate Letters
- LeetCode  : https://leetcode.com/problems/remove-duplicate-letters/
- Problem # : 316
- Difficulty: Medium
- Topic     : String, Stack, Monotonic Stack, Greedy
 *
- Approach:
- Track the last occurrence of each character. Keep a boolean array of characters currently in the stack.
- Iterate. If a character is already in the stack, skip it.
- Maintain a monotonic increasing stack: pop characters that are lexicographically larger than the current character IF they appear again later in the string.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (26 characters max)
- ============================================================
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_seen(26, 0);
        vector<bool> in_stack(26, false);
        string st = ""; // String acting as stack
        
        for (int i = 0; i < s.length(); i++) {
            last_seen[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (in_stack[c - 'a']) continue;
            
            while (!st.empty() && st.back() > c && last_seen[st.back() - 'a'] > i) {
                in_stack[st.back() - 'a'] = false;
                st.pop_back();
            }
            
            st.push_back(c);
            in_stack[c - 'a'] = true;
        }
        
        return st;
    }
};

/*
- Key Learnings:
- A Monotonic Increasing Stack forces a lexicographical sort natively.
- The 'last_seen' map ensures you never pop a character that won't appear again, satisfying the requirement to keep exactly one of every character.
 *
- Status: Accepted
 */