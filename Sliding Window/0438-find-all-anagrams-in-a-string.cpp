/*
- ============================================================
- Problem   : Find All Anagrams in a String
- LeetCode  : https://leetcode.com/problems/find-all-anagrams-in-a-string/
- Problem # : 438
- Difficulty: Medium
- Topic     : Hash Table, String, Sliding Window
 *
- Approach:
- Create a target frequency array for string 'p' and a window frequency array for string 's'.
- Slide a fixed-size window of length 'p' across 's'. If the frequency arrays match, record the start index.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length()) return res;
        
        vector<int> p_count(26, 0), s_count(26, 0);
        for (int i = 0; i < p.length(); i++) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }
        
        if (p_count == s_count) res.push_back(0);
        
        for (int i = p.length(); i < s.length(); i++) {
            s_count[s[i] - 'a']++;
            s_count[s[i - p.length()] - 'a']--;
            
            if (p_count == s_count) {
                res.push_back(i - p.length() + 1);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- C++ std::vector equality (==) overload allows for instant, clean array comparisons without writing a manual for-loop.
- Fixed-size sliding windows add the new element and remove the trailing element in a single loop step.
 *
- Status: Accepted
 */