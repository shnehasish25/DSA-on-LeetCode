/*
- ============================================================
- Problem   : Find the K-Beauty of a Number
- LeetCode  : https://leetcode.com/problems/find-the-k-beauty-of-a-number/
- Problem # : 2269
- Difficulty: Easy
- Topic     : Math, String, Sliding Window
 *
- Approach:
- Convert the number to a string to easily extract sliding windows of length 'k'.
- Convert each substring back to an integer and check if the original number is divisible by it.
 *
- Time Complexity  : O(N) where N is number of digits
- Space Complexity : O(N) for string conversion
- ============================================================
 */

#include <string>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
        
        for (int i = 0; i <= s.length() - k; i++) {
            string sub = s.substr(i, k);
            int val = stoi(sub);
            
            if (val != 0 && num % val == 0) {
                count++;
            }
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Sliding windows don't have to be arrays. Strings are perfectly suited for fixed-size window slicing.
- Protect against division by zero (val != 0) since '00' or '0' strings cast to a zero integer.
 *
- Status: Accepted
 */