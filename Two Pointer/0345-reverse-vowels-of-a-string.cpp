/*
- ============================================================
- Problem   : Reverse Vowels of a String
- LeetCode  : https://leetcode.com/problems/reverse-vowels-of-a-string/
- Problem # : 345
- Difficulty: Easy
- Topic     : Two Pointers, String
 *
- Approach:
- Place pointers at both ends of the string.
- Move them inward until both point to vowels, then swap them. Repeat until pointers cross.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

/*
- Key Learnings:
- The exact same logic as 'Valid Palindrome' (skipping irrelevant characters) can be repurposed for targeted in-place swaps.
- A helper function for condition checks (like isVowel) keeps the two-pointer loop clean and readable.
 *
- Status: Accepted
 */