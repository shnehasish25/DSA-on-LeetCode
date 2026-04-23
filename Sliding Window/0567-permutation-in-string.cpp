/*
- ============================================================
- Problem   : Permutation in String
- LeetCode  : https://leetcode.com/problems/permutation-in-string/
- Problem # : 567
- Difficulty: Medium
- Topic     : Hash Table, Two Pointers, String, Sliding Window
 *
- Approach:
- Identical logic to "Find All Anagrams in a String". Maintain a fixed-size sliding window of length s1 over s2.
- Compare character frequencies. Return true as soon as one valid window is found.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_count(26, 0), s2_count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        if (s1_count == s2_count) return true;
        
        for (int i = s1.length(); i < s2.length(); i++) {
            s2_count[s2[i] - 'a']++;
            s2_count[s2[i - s1.length()] - 'a']--;
            
            if (s1_count == s2_count) return true;
        }
        
        return false;
    }
};

/*
- Key Learnings:
- Anagrams and Permutations are mathematically identical in frequency mapping problems.
- If you know how to solve 438, you know how to solve 567. Just change the return type to boolean.
 *
- Status: Accepted
 */