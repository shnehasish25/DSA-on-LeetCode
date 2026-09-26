/*
- ============================================================
- Problem   : Decode String
- LeetCode  : https://leetcode.com/problems/decode-string/
- Problem # : 394
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Use two stacks: one for repetition multipliers (counts) and one for building string fragments (strings).
- On '[': Push current string and current number to stacks, reset both.
- On ']': Pop number and string, multiply the current string by the number, and append it to the popped string.
 *
- Time Complexity  : O(n * max_k) where max_k is the repetition count
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string curr_str = "";
        int curr_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                curr_num = curr_num * 10 + (c - '0');
            } else if (isalpha(c)) {
                curr_str += c;
            } else if (c == '[') {
                counts.push(curr_num);
                strings.push(curr_str);
                curr_num = 0;
                curr_str = "";
            } else if (c == ']') {
                int repeat = counts.top(); counts.pop();
                string prev_str = strings.top(); strings.pop();
                
                for (int i = 0; i < repeat; i++) {
                    prev_str += curr_str;
                }
                curr_str = prev_str;
            }
        }
        
        return curr_str;
    }
};

/*
- Key Learnings:
- Complex nested parsing heavily relies on "State Stashing". The '[' character acts as the trigger to save the current state and begin fresh.
- Building the multiplier dynamically (curr = curr * 10 + digit) correctly handles multi-digit numbers like "100[a]".
 *
- Status: Accepted
 */