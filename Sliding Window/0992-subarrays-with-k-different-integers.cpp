/*
- ============================================================
- Problem   : Subarrays with K Different Integers
- LeetCode  : https://leetcode.com/problems/subarrays-with-k-different-integers/
- Problem # : 992
- Difficulty: Hard
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Find subarrays with EXACTLY 'k' distinct integers by calculating (Subarrays with <= k distinct) - (Subarrays with <= k-1 distinct).
- Use a sliding window helper function with a frequency map to find the "at most k" count.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int left = 0, res = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (counts[nums[right]] == 0) k--;
            counts[nums[right]]++;
            
            while (k < 0) {
                counts[nums[left]]--;
                if (counts[nums[left]] == 0) k++;
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

/*
- Key Learnings:
- The AtMost(K) - AtMost(K-1) pattern is the absolute gold standard for "exactly K" sliding window problems.
- Tracking distinct elements is handled cleanly by decrementing the budget 'k' only when an element's count goes from 0 to 1.
 *
- Status: Accepted
 */