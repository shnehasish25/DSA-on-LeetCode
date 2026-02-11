/*
- ============================================================
- Problem   : Random Pick with Weight
- LeetCode  : https://leetcode.com/problems/random-pick-with-weight/
- Problem # : 528
- Difficulty: Medium
- Topic     : Array, Math, Binary Search, Prefix Sum
 *
- Approach:
- Build a prefix sum array of the weights. The total sum represents the total probability space.
- Generate a random number between 1 and the total sum, then use binary search (lower_bound) to find the target index.
 *
- Time Complexity  : O(n) constructor, O(log n) pickIndex
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> prefix_sums;
public:
    Solution(vector<int>& w) {
        int current_sum = 0;
        for (int weight : w) {
            current_sum += weight;
            prefix_sums.push_back(current_sum);
        }
    }
    
    int pickIndex() {
        int target = rand() % prefix_sums.back() + 1;
        auto it = lower_bound(prefix_sums.begin(), prefix_sums.end(), target);
        return it - prefix_sums.begin();
    }
};

/*
- Key Learnings:
- Prefix Sum transforms independent weights into contiguous ranges on a number line, enabling proportional random selection.
- std::lower_bound handles the O(log n) search perfectly, finding the first prefix sum greater than or equal to the random target.
 *
- Status: Accepted
 */