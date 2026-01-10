/*
- ============================================================
- Problem   : Range Sum Query - Immutable
- LeetCode  : https://leetcode.com/problems/range-sum-query-immutable/
- Problem # : 303
- Difficulty: Easy
- Topic     : Array, Design, Prefix Sum
 *
- Approach:
- Precompute the prefix sum array in the constructor.
- To find the sum between indices 'left' and 'right', subtract the prefix sum just before 'left' from the prefix sum at 'right'.
 *
- Time Complexity  : O(n) constructor, O(1) per query
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(0); // Dummy node to handle left == 0 gracefully
        int current_sum = 0;
        for (int num : nums) {
            current_sum += num;
            prefix.push_back(current_sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/*
- Key Learnings:
- Prefix Sum reduces O(n) range queries to O(1) instant lookups.
- Adding a 0 at the beginning of the prefix array (making it size n + 1) prevents messy "if (left == 0)" edge cases.
 *
- Status: Accepted
 */