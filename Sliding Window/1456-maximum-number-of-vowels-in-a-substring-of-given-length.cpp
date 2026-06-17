/*
- ============================================================
- Problem   : Maximum Number of Vowels in a Substring of Given Length
- LeetCode  : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
- Problem # : 1456
- Difficulty: Medium
- Topic     : String, Sliding Window
 *
- Approach:
- Slide a fixed window of size 'k' over the string.
- Keep a running count of vowels. Add 1 if the incoming character is a vowel, subtract 1 if the outgoing character is a vowel.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int current_vowels = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) current_vowels++;
        }
        
        int max_vowels = current_vowels;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i])) current_vowels++;
            if (isVowel(s[i - k])) current_vowels--;
            
            max_vowels = max(max_vowels, current_vowels);
        }
        
        return max_vowels;
    }
};

/*
- Key Learnings:
- Directly models the fixed sliding window pattern exactly like finding maximum average. 
- Boolean helper functions keep the sliding window conditions clean and highly readable.
 *
- Status: Accepted
 */