/*
- ============================================================
- Problem   : Valid Palindrome
- LeetCode  : https://leetcode.com/problems/valid-palindrome/
- Problem # : 125
- Difficulty: Easy
- Topic     : Two Pointers, String
 *
- Approach:
- Use two pointers, one at the start and one at the end.
- Skip non-alphanumeric characters, convert valid characters to lowercase, and check if they match as the pointers move inward.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // 1. Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // 2. Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // 3. Compare the characters in lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

/*
- Key Learnings:
- Using built-in functions like isalnum() and tolower() keeps the code exceptionally clean.
- Two pointers meeting in the middle is the optimal O(1) space approach compared to building a cleaned, reversed string in memory.
 *
- Status: Accepted
 */