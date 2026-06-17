/*
- ============================================================
- Problem   : Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
- LeetCode  : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
- Problem # : 1438
- Difficulty: Medium
- Topic     : Array, Sliding Window, Ordered Set, Monotonic Queue
 *
- Approach:
- Use a multiset to keep the window's elements sorted dynamically.
- The maximum absolute difference in the window is always the last element minus the first element of the multiset.
- If this diff exceeds the limit, shrink from the left by removing nums[left] from the multiset.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int left = 0, max_len = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            window.insert(nums[right]);
            
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[left]));
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- std::multiset provides an easy way to maintain a sorted sliding window, accessing the min and max in O(1) time.
- Always use multiset::find(val) when erasing a single element, because multiset::erase(val) would delete ALL copies of that value.
 *
- Status: Accepted
 */