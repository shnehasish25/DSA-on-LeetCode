/*
- ============================================================
- Problem   : Circular Array Loop
- LeetCode  : https://leetcode.com/problems/circular-array-loop/
- Problem # : 457
- Difficulty: Medium
- Topic     : Array, Two Pointers
 *
- Approach:
- Use fast and slow pointers tracking index jumps.
- Verify cycles ensure constant direction (all positive/all negative) and length > 1.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            int slow = i, fast = next(nums, i);
            while (nums[fast] * nums[i] > 0 && nums[next(nums, fast)] * nums[i] > 0) {
                if (slow == fast) {
                    if (slow == next(nums, slow)) break; 
                    return true;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nxt = next(nums, j);
                nums[j] = 0;
                j = nxt;
            }
        }
        return false;
    }
};

/*
- Key Learnings:
- The next step function (handling negative modulos in C++) is the engine for array-based cycles.
- Zeroing out visited paths as we fail prevents O(n^2) time complexity by short-circuiting future iterations.
 *
- Status: Accepted
 */