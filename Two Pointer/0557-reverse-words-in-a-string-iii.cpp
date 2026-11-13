/*
- ============================================================
- Problem   : Reverse Words in a String III
- LeetCode  : https://leetcode.com/problems/reverse-words-in-a-string-iii/
- Problem # : 557
- Difficulty: Easy
- Topic     : Two Pointers, String
 *
- Approach:
- Scan through the string with a fast pointer.
- When a space or string end is found, reverse the characters strictly within the current word using a localized two-pointer swap.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                int left = start, right = i - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++; right--;
                }
                start = i + 1;
            }
        }
        return s;
    }
};

/*
- Key Learnings:
- Strings can be safely modified in-place segment by segment.
- Iterating one extra step (i <= length) acts as a clever trick to process the final word without writing a separate block of code.
 *
- Status: Accepted
 */