/*
- ============================================================
- Problem   : Longest Subsequence With Limited Sum
- LeetCode  : https://leetcode.com/problems/longest-subsequence-with-limited-sum/
- Problem # : 2389
- Difficulty: Easy
- Topic     : Array, Binary Search, Greedy, Prefix Sum
 *
- Approach:
- Sort the array (since subsequence allows picking elements from anywhere, greedy choice is to pick the smallest elements).
- Compute the prefix sum of the sorted array.
- For each query, use binary search (upper_bound) to find the maximum number of elements whose sum is <= the query limit.
 *
- Time Complexity  : O((n + m) log n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> prefix;
        int current = 0;
        for (int x : nums) {
            current += x;
            prefix.push_back(current);
        }
        
        vector<int> res;
        for (int q : queries) {
            auto it = upper_bound(prefix.begin(), prefix.end(), q);
            res.push_back(it - prefix.begin());
        }
        
        return res;
    }
};

/*
- Key Learnings:
- A "Subsequence" allows reordering because element order doesn't dictate presence. Greedy sorting unlocks the prefix sum capability.
- std::upper_bound finds the first element strictly greater than the query, which directly translates to the valid count (index).
 *
- Status: Accepted
 */