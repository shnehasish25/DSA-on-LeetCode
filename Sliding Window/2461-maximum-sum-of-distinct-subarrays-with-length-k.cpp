/*
- ============================================================
- Problem   : Maximum Sum of Distinct Subarrays With Length K
- LeetCode  : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
- Problem # : 2461
- Difficulty: Medium
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Use a sliding window of fixed size 'k'. Use a hash map to track element frequencies to ensure all elements are distinct.
- Add to the sum. If an element's frequency > 1, the window is invalid even if size == k.
- Keep updating max sum for valid windows.
 *
- Time Complexity  : O(n)
- Space Complexity : O(k)
- ============================================================
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long current_sum = 0, max_sum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            current_sum += nums[right];
            
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                current_sum -= nums[left];
                left++;
            }
            
            if (right - left + 1 == k && freq.size() == k) {
                max_sum = max(max_sum, current_sum);
            }
        }
        
        return max_sum;
    }
};

/*
- Key Learnings:
- A window of size 'k' is strictly composed of distinct elements if and only if the hash map's size equals 'k'.
- Erasing keys with 0 frequencies is mandatory for the map size check to remain accurate.
 *
- Status: Accepted
 */