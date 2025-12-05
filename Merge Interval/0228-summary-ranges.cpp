/*
- ============================================================
- Problem   : Summary Ranges
- LeetCode  : https://leetcode.com/problems/summary-ranges/
- Problem # : 228
- Difficulty: Easy
- Topic     : Array
 *
- Approach:
- Iterate through the sorted array. Keep track of the start of the current range.
- When the current number + 1 does not equal the next number, the range breaks. Format the string and update the start.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) excluding output
- ============================================================
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        
        int start = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if it's the last element or the sequence breaks
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1]) {
                if (start == nums[i]) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                if (i != nums.size() - 1) {
                    start = nums[i + 1];
                }
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- A great fundamental problem on how to dynamically group contiguous elements into intervals.
- The condition (nums[i] + 1 != nums[i+1]) cleanly identifies the exact end of a sequence without complex tracking.
 *
- Status: Accepted
 */