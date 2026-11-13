/*
- ============================================================
- Problem   : Assign Cookies
- LeetCode  : https://leetcode.com/problems/assign-cookies/
- Problem # : 455
- Difficulty: Easy
- Topic     : Array, Two Pointers, Greedy, Sorting
 *
- Approach:
- Sort both the greed factors (g) and cookie sizes (s).
- Use two pointers to match the smallest valid cookie to the least greedy child first.
 *
- Time Complexity  : O(n log n + m log m)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child_idx = 0, cookie_idx = 0;
        while (child_idx < g.size() && cookie_idx < s.size()) {
            if (s[cookie_idx] >= g[child_idx]) {
                child_idx++; // Cookie satisfies child, move to next child
            }
            cookie_idx++; // Always move to next cookie
        }
        return child_idx;
    }
};

/*
- Key Learnings:
- Combining Greedy algorithms with Two Pointers usually requires sorting the arrays first.
- Matching the smallest valid cookie to the smallest child greed guarantees maximum total matches.
 *
- Status: Accepted
 */