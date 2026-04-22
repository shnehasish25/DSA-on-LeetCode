/*
- ============================================================
- Problem   : Sliding Window Maximum
- LeetCode  : https://leetcode.com/problems/sliding-window-maximum/
- Problem # : 239
- Difficulty: Hard
- Topic     : Array, Sliding Window, Monotonic Queue
 *
- Approach:
- Use a deque to store indices of elements, maintaining a strictly decreasing order of values.
- As the window slides, remove indices out of bounds from the front, and smaller elements from the back. The front is always the maximum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(k)
- ============================================================
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

/*
- Key Learnings:
- The Monotonic Queue is the only way to process sliding range maximums/minimums in true O(n) time.
- Always store indices in the deque, not the values themselves, so you can calculate when an element falls out of the sliding window.
 *
- Status: Accepted
 */