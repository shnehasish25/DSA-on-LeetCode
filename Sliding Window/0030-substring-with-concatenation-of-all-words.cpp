/*
- ============================================================
- Problem   : Substring with Concatenation of All Words
- LeetCode  : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
- Problem # : 30
- Difficulty: Hard
- Topic     : Hash Table, String, Sliding Window
 *
- Approach:
- The words are of identical length 'word_len'. Set up 'word_len' parallel sliding windows.
- Within each pass, slide a window by 'word_len' steps, tracking word frequencies in a hash map just like "Find All Anagrams".
 *
- Time Complexity  : O(N * L) where N is string length, L is word length
- Space Complexity : O(M) where M is number of words
- ============================================================
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        
        int word_len = words[0].length();
        int word_count = words.size();
        int total_len = word_len * word_count;
        
        unordered_map<string, int> word_map;
        for (string& w : words) word_map[w]++;
        
        for (int i = 0; i < word_len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            
            for (int right = i; right + word_len <= s.length(); right += word_len) {
                string word = s.substr(right, word_len);
                
                if (word_map.count(word)) {
                    seen[word]++;
                    count++;
                    
                    while (seen[word] > word_map[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }
                    
                    if (count == word_count) {
                        res.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }
        return res;
    }
};

/*
- Key Learnings:
- Offsetting the start index by 0, 1, ..., word_len-1 ensures we check every possible alignment.
- This is the exact same logic as string anagram sliding windows, just jumping by 'word_len' instead of character by character.
 *
- Status: Accepted
 */