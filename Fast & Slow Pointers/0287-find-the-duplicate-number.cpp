/*
- ============================================================
- Problem   : Find the Duplicate Number
- LeetCode  : https://leetcode.com/problems/find-the-duplicate-number/
- Problem # : 287
- Difficulty: Medium
- Topic     : Array, Two Pointers
 *
- Approach:
- Treat array values as pointer indices. A duplicate value causes multiple pointers to target the same index, forming a cycle.
- Apply Floyd's Cycle detection to find the cycle entrance (the duplicate).
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        
        return slow;
    }
};

/*
- Key Learnings:
- Array bounds [1, n] mapping to indexes [0, n] perfectly simulate a linked list graph.
- This fulfills the strict constraints: no array modification, O(1) space, and O(n) time.
 *
- Status: Accepted
 */