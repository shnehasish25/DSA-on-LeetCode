/*
- ============================================================
- Problem   : Can Make Palindrome from Substring
- LeetCode  : https://leetcode.com/problems/can-make-palindrome-from-substring/
- Problem # : 1177
- Difficulty: Medium
- Topic     : Array, Hash Table, String, Bit Manipulation, Prefix Sum
 *
- Approach:
- A palindrome query only cares about character frequency parities (odd or even).
- Use a 32-bit integer to track the parity of all 26 characters (Prefix XOR).
- For a query [L, R], the required replacements to make a palindrome is (set_bits / 2).
 *
- Time Complexity  : O(n + q)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int bit = 1 << (s[i] - 'a');
            prefix[i + 1] = prefix[i] ^ bit;
        }
        
        vector<bool> res;
        for (const auto& q : queries) {
            int L = q[0], R = q[1], K = q[2];
            
            int mask = prefix[R + 1] ^ prefix[L];
            int odd_count = __builtin_popcount(mask);
            
            res.push_back(odd_count / 2 <= K);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- An integer's bits serve perfectly as a lightweight Hash Map for states <= 32 options (like 26 alphabet letters).
- Prefix XOR provides the exact parity states of a substring instantly. __builtin_popcount is a hyper-fast C++ intrinsic to count active bits.
 *
- Status: Accepted
 */