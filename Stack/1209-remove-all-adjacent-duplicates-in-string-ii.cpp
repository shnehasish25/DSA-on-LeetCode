/*
- ============================================================
- Problem   : Remove All Adjacent Duplicates in String II
- LeetCode  : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
- Problem # : 1209
- Difficulty: Medium
- Topic     : String, Stack
 *
- Approach:
- Use a stack storing pairs of {character, count}.
- Iterate through the string. If the top character matches, increment its count.
- If the count reaches 'k', pop it off the stack. Build the final string by expanding the remaining pairs.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back();
                }
            } else {
                st.push_back({c, 1});
            }
        }
        
        string res = "";
        for (const auto& p : st) {
            res.append(p.second, p.first);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Expanding the stack node to hold frequency state prevents O(k) worst-case consecutive pops.
- string::append(count, char) is the most efficient way to rebuild character chunks.
 *
- Status: Accepted
 */