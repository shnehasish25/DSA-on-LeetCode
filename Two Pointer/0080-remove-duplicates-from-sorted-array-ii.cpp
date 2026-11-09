/*
- ============================================================
- Problem   : Remove Duplicates from Sorted Array II
- LeetCode  : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
- Problem # : 80
- Difficulty: Medium
- Topic     : Array, Two Pointers
 *
- Approach:
- Keep a slow pointer for the insertion index.
- Since up to two duplicates are allowed, check if the current element equals the element two positions behind the insertion pointer.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int insert_pos = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[insert_pos - 2]) {
                nums[insert_pos] = nums[i];
                insert_pos++;
            }
        }
        return insert_pos;
    }
};

/*
- Key Learnings:
- Checking against 'insert_pos - 2' elegantly generalizes the removal pattern. For 'k' allowed duplicates, you just check 'insert_pos - k'.
- We start loops at index 2 because the first two elements are always guaranteed to be valid.
 *
- Status: Accepted
 */