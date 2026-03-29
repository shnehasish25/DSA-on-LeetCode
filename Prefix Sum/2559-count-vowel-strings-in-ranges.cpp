/*
- ============================================================
- Problem   : Count Vowel Strings in Ranges
- LeetCode  : https://leetcode.com/problems/count-vowel-strings-in-ranges/
- Problem # : 2559
- Difficulty: Medium
- Topic     : Array, String, Prefix Sum
 *
- Approach:
- Create a boolean array checking if a word starts and ends with a vowel.
- Transform this into a prefix sum array. For each query [L, R], the answer is prefix[R+1] - prefix[L].
 *
- Time Complexity  : O(n + q)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    bool isValid(string& s) {
        return isVowel(s[0]) && isVowel(s.back());
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (isValid(words[i]) ? 1 : 0);
        }
        
        vector<int> res;
        for (const auto& q : queries) {
            res.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Prefix sum seamlessly extends to querying counts/booleans instead of strictly just summing large numbers.
- Abstracting string validity checks into a helper makes the array build logic perfectly readable.
 *
- Status: Accepted
 */