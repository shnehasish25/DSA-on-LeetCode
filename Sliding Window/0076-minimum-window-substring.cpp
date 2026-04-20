/*
- ============================================================
- Problem   : Minimum Window Substring
- LeetCode  : https://leetcode.com/problems/minimum-window-substring/
- Problem # : 76
- Difficulty: Hard
- Topic     : Hash Table, String, Sliding Window
 *
- Approach:
- Track required character frequencies from string 't'. Expand the window by moving 'right' until all required characters are found.
- Once valid, shrink from 'left' to minimize the window size while keeping it valid. Keep track of the minimum window coordinates.
 *
- Time Complexity  : O(m + n)
- Space Complexity : O(1) (128 ASCII array)
- ============================================================
 */

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (char c : t) map[c]++;
        
        int counter = t.length(), left = 0, right = 0, min_len = INT_MAX, min_start = 0;
        
        while (right < s.length()) {
            if (map[s[right]] > 0) counter--;
            map[s[right]]--;
            right++;
            
            while (counter == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }
                map[s[left]]++;
                if (map[s[left]] > 0) counter++;
                left++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};

/*
- Key Learnings:
- The "counter" variable acts as a master switch, avoiding the need to iterate through the frequency map at every step.
- Expanding and then aggressively shrinking is the definitive pattern for "Minimum Window" problems.
 *
- Status: Accepted
 */