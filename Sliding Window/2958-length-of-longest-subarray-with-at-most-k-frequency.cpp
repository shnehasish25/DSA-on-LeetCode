/*
- ============================================================
- Problem   : Length of Longest Subarray With at Most K Frequency
- LeetCode  : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
- Problem # : 2958
- Difficulty: Medium
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Use a sliding window with a hash map to track the frequency of each element.
- If the current element's frequency exceeds 'k', shrink the window from the left until that specific element's frequency is back to 'k'.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, max_len = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

/*
- Key Learnings:
- The while loop constraint strictly focuses on the newly added element (nums[right]), because it's the only one that could have just violated the 'k' rule.
- Extremely readable map logic that mirrors Longest Substring Without Repeating Characters.
 *
- Status: Accepted
 */