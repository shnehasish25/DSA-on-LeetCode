/*
- ============================================================
- Problem   : Remove Element
- LeetCode  : https://leetcode.com/problems/remove-element/
- Problem # : 27
- Difficulty: Easy
- Topic     : Array, Two Pointers
 *
- Approach:
- Use a slow pointer (insert_pos) to track where valid elements go.
- Iterate with a fast pointer; if the current value isn't the target, place it at the slow pointer and increment.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int insert_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[insert_pos] = nums[i];
                insert_pos++;
            }
        }
        return insert_pos;
    }
};

/*
- Key Learnings:
- Fast/Slow pointers make in-place deletion trivial by overwriting 'deleted' values rather than actually erasing them from memory.
- The returned value is both the length of the new array and the index of the next insertion.
 *
- Status: Accepted
 */