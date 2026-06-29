/*
- ============================================================
- Problem   : Maximize the Confusion of an Exam
- LeetCode  : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
- Problem # : 2024
- Difficulty: Medium
- Topic     : String, Sliding Window
 *
- Approach:
- This is asking for the longest consecutive 'T's or 'F's with at most 'k' flips allowed.
- Find the longest sequence of 'T's (allowing k 'F's) and the longest sequence of 'F's (allowing k 'T's), and take the maximum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    int maxConsecutive(string& answerKey, int k, char target) {
        int left = 0, modifications = 0, max_len = 0;
        
        for (int right = 0; right < answerKey.length(); right++) {
            if (answerKey[right] != target) {
                modifications++;
            }
            
            while (modifications > k) {
                if (answerKey[left] != target) modifications--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutive(answerKey, k, 'T'), maxConsecutive(answerKey, k, 'F'));
    }
};

/*
- Key Learnings:
- Running the exact same sliding window logic twice (once optimizing for T, once for F) is cleaner than trying to manage both states in a single chaotic pass.
- Mechanically identical to "Max Consecutive Ones III".
 *
- Status: Accepted
 */