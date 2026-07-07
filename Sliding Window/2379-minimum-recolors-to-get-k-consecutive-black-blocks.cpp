/*
- ============================================================
- Problem   : Minimum Recolors to Get K Consecutive Black Blocks
- LeetCode  : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
- Problem # : 2379
- Difficulty: Easy
- Topic     : String, Sliding Window
 *
- Approach:
- Use a fixed sliding window of size 'k'.
- Count how many 'W' (white blocks) are inside the window. The minimum number of 'W's seen across all windows is the minimum recolors needed.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white_count = 0, min_recolors = k;
        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white_count++;
        }
        min_recolors = white_count;
        
        for (int i = k; i < blocks.length(); i++) {
            if (blocks[i] == 'W') white_count++;
            if (blocks[i - k] == 'W') white_count--;
            min_recolors = min(min_recolors, white_count);
        }
        
        return min_recolors;
    }
};

/*
- Key Learnings:
- Recoloring cost perfectly correlates to the count of the undesired character in the window.
- A textbook example of the fixed-size sliding window initialization + loop shift pattern.
 *
- Status: Accepted
 */