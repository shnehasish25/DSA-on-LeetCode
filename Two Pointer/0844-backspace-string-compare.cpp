/*
- ============================================================
- Problem   : Backspace String Compare
- LeetCode  : https://leetcode.com/problems/backspace-string-compare/
- Problem # : 844
- Difficulty: Easy
- Topic     : Two Pointers, String, Stack
 *
- Approach:
- Traverse both strings backwards using two pointers, keeping track of how many '#' backspaces we have accumulated.
- Skip deleted characters, then compare the remaining valid characters one by one.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ps = s.length() - 1, pt = t.length() - 1;
        int skip_s = 0, skip_t = 0;
        
        while (ps >= 0 || pt >= 0) {
            while (ps >= 0) {
                if (s[ps] == '#') { skip_s++; ps--; }
                else if (skip_s > 0) { skip_s--; ps--; }
                else break;
            }
            while (pt >= 0) {
                if (t[pt] == '#') { skip_t++; pt--; }
                else if (skip_t > 0) { skip_t--; pt--; }
                else break;
            }
            
            if (ps >= 0 && pt >= 0 && s[ps] != t[pt]) return false;
            if ((ps >= 0) != (pt >= 0)) return false;
            ps--; pt--;
        }
        return true;
    }
};

/*
- Key Learnings:
- The intuitive solution is O(n) space using a Stack, but processing the string right-to-left dynamically resolves backspaces in O(1) space.
- A "skip counter" perfectly mimics stack pop behavior on string arrays.
 *
- Status: Accepted
 */