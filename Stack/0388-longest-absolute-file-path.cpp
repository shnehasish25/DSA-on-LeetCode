/*
- ============================================================
- Problem   : Longest Absolute File Path
- LeetCode  : https://leetcode.com/problems/longest-absolute-file-path/
- Problem # : 388
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Parse the string by newline ('\n'). Count the tabs ('\t') to determine directory depth.
- Use a stack (or an array acting as a stack) to track the accumulated length of the path at each depth level.
- If the current item has a '.', it is a file; update the max length.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> path_len(input.length() + 1, 0); // Stores length up to a certain depth
        int max_len = 0;
        
        stringstream ss(input);
        string token;
        
        while (getline(ss, token, '\n')) {
            int depth = 0;
            while (token[depth] == '\t') {
                depth++;
            }
            
            int name_len = token.length() - depth;
            
            if (token.find('.') != string::npos) {
                max_len = max(max_len, path_len[depth] + name_len);
            } else {
                path_len[depth + 1] = path_len[depth] + name_len + 1; // +1 for the '/'
            }
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- The depth inherently represents a stack level. Overwriting an array index at the current depth effectively "pops" the old directory and "pushes" the new one.
 *
- Status: Accepted
 */