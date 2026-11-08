/*
- ============================================================
- Problem   : Remove Duplicates from Sorted Array
- LeetCode  : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
- Problem # : 26
- Difficulty: Easy
- Topic     : Array, Two Pointers
 *
- Approach:
- Use a slow pointer (insert_pos) to track where the next unique element should go.
- Use a fast pointer (i) to iterate through the array, skipping duplicates and copying unique elements to the slow pointer position.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // 1. The first element is always unique, so insert position starts at 1
        int insert_pos = 1;
        
        // 2. Fast pointer scans the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // 3. If we find a new unique element
            if (nums[i] != nums[i - 1]) {
                nums[insert_pos] = nums[i]; // Overwrite in-place
                insert_pos++;               // Move the insertion pointer forward
            }
        }
        
        return insert_pos;
    }
};

/*
- Key Learnings:
- In-place modification relies heavily on the "Slow Pointer / Fast Pointer" variant of the two-pointer pattern.
- We don't need to actually delete the duplicates; we just overwrite them and return the new logical size of the array.
 *
- Status: Accepted
 */