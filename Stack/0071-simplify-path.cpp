/*
- ============================================================
- Problem   : Simplify Path
- LeetCode  : https://leetcode.com/problems/simplify-path/
- Problem # : 71
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Parse the string by splitting on '/'. 
- Use a stack to track directories. Ignore '.' and empty strings. If '..', pop from the stack if it's not empty.
- Finally, reconstruct the path from the stack.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string temp;
        
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            if (temp == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(temp);
            }
        }
        
        string res = "";
        for (const string& dir : stack) {
            res += "/" + dir;
        }
        
        return res.empty() ? "/" : res;
    }
};

/*
- Key Learnings:
- C++ std::vector acts as a perfect stack here because we need to iterate from bottom to top at the end to build the string (std::stack doesn't allow iteration).
- stringstream with getline is the cleanest way to split strings by a delimiter in C++.
 *
- Status: Accepted
 */