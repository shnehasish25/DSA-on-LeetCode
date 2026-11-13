/*
- ============================================================
- Problem   : Valid Palindrome II
- LeetCode  : https://leetcode.com/problems/valid-palindrome-ii/
- Problem # : 680
- Difficulty: Easy
- Topic     : Two Pointers, String, Greedy
 *
- Approach:
- Use outer two pointers to check palindrome status.
- On the first mismatch, recursively/separately check if the remainder is a palindrome by skipping either the left character or the right character.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    bool isPalinRange(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalinRange(s, left + 1, right) || isPalinRange(s, left, right - 1);
            }
            left++; right--;
        }
        return true;
    }
};

/*
- Key Learnings:
- Handling exactly "one deletion allowed" means branching your two-pointer check exactly once into two standard palindrome sub-checks.
- Greedy strategy: the first mismatch you hit MUST be the spot where you spend your single deletion.
 *
- Status: Accepted
 */