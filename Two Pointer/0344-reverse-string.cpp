/*
- ============================================================
- Problem   : Reverse String
- LeetCode  : https://leetcode.com/problems/reverse-string/
- Problem # : 344
- Difficulty: Easy
- Topic     : Two Pointers, String
 *
- Approach:
- Use two pointers, one at the beginning and one at the end of the character array.
- Swap the characters at these pointers and move them towards the center until they meet.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // 1. Swap characters at the outer edges
            swap(s[left], s[right]);
            
            // 2. Move pointers inward
            left++;
            right--;
        }
    }
};

/*
- Key Learnings:
- This is the most fundamental two-pointer problem. It perfectly illustrates how pointers can converge to modify arrays in-place.
- Using std::swap keeps the code minimal and avoids manual temporary variable creation.
 *
- Status: Accepted
 */