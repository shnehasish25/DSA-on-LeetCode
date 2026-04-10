/*
- ============================================================
- Problem   : Longest Substring Without Repeating Characters
- LeetCode  : https://leetcode.com/problems/longest-substring-without-repeating-characters/
- Problem # : 3
- Difficulty: Medium
- Topic     : Hash Table, String, Sliding Window
 *
- Approach:
- Use a sliding window with two pointers. Track the last seen index of each character using an array or hash map.
- If a character is repeated and its last seen index is within the current window, shrink the window by moving the left pointer just past the previous occurrence.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (fixed 128 ASCII chars)
- ============================================================
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1);
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- Using a fixed-size vector for ASCII characters is significantly faster than using an unordered_map.
- Jumping the left pointer directly to 'last_seen + 1' prevents the need for an inner while loop.
 *
- Status: Accepted
 */