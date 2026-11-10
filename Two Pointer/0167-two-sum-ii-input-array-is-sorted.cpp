/*
- ============================================================
- Problem   : Two Sum II - Input Array Is Sorted
- LeetCode  : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
- Problem # : 167
- Difficulty: Medium
- Topic     : Array, Two Pointers, Binary Search
 *
- Approach:
- Since the array is already sorted, use a two-pointer approach starting from both ends.
- Calculate the sum of the elements at the pointers: if it's too small, move the left pointer right; if it's too large, move the right pointer left.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1; 

        while (start < end) {
            int sum = numbers[start] + numbers[end];
            
            // 1. Target found, return 1-based indices as requested by the problem
            if (sum == target) {
                return {start + 1, end + 1};
            }
            // 2. Sum is too small, move the left pointer to increase the sum
            else if (sum < target) {
                start++;
            }
            // 3. Sum is too large, move the right pointer to decrease the sum
            else {
                end--;
            }
        }
        
        return {}; 
    }
};

/*
- Key Learnings:
- The sorted property of the array allows us to optimize space to O(1) by avoiding the hash map used in standard Two Sum.
- Be careful with problem constraints: this specific variation asks for 1-based indexing, requiring a "+1" adjustment on the return values.
 *
- Status: Accepted
 */