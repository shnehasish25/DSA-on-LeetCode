/*
- ============================================================
- Problem   : Move Zeroes
- LeetCode  : https://leetcode.com/problems/move-zeroes/
- Problem # : 283
- Difficulty: Easy
- Topic     : Array, Two Pointers
 *
- Approach:
- Use a slow pointer to keep track of the position where the next non-zero element should be written.
- Iterate through the array; if the current element is non-zero, swap it with the slow pointer and increment.
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
    void moveZeroes(vector<int>& nums) {
        int insert_pos = 0; // Pointer for the next non-zero element
        
        // 1. Shift all non-zero elements to the front, maintaining their relative order
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[insert_pos], nums[i]);
                insert_pos++;
            }
        }
        // Elements from insert_pos to the end are naturally 0s because of the swaps
    }
};

/*
- Key Learnings:
- Swapping non-zeroes with the insert_pos guarantees that we push zeroes to the back without needing a second loop to fill the zeroes.
- This is a direct application of the QuickSort partition scheme logic (using 0 as the pivot).
 *
- Status: Accepted
 */