/*
- ============================================================
- Problem   : Longest Repeating Character Replacement
- LeetCode  : https://leetcode.com/problems/longest-repeating-character-replacement/
- Problem # : 424
- Difficulty: Medium
- Topic     : Hash Table, String, Sliding Window
 *
- Approach:
- Track character counts in the current window and the frequency of the most common character (max_freq).
- The window is valid if (window size - max_freq <= k). If invalid, shrink from the left.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int left = 0, max_freq = 0, max_len = 0;
        
        for (int right = 0; right < s.length(); right++) {
            counts[s[right] - 'A']++;
            max_freq = max(max_freq, counts[s[right] - 'A']);
            
            if ((right - left + 1) - max_freq > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- We do not need to strictly decrement max_freq when the left pointer moves. We only care about finding a window larger than our historical max_len.
- 'Window size minus highest frequency' gives the exact number of substitutions needed.
 *
- Status: Accepted
 */