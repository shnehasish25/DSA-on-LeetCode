/*
- ============================================================
- Problem   : Maximum Length of Pair Chain
- LeetCode  : https://leetcode.com/problems/maximum-length-of-pair-chain/
- Problem # : 646
- Difficulty: Medium
- Topic     : Array, Dynamic Programming, Greedy, Sorting
 *
- Approach:
- Sort pairs by their END time.
- Greedily pick the first pair. For subsequent pairs, if their start time is greater than the current pair's end time, they can be chained.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int current_end = pairs[0][1];
        int count = 1;
        
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > current_end) {
                count++;
                current_end = pairs[i][1];
            }
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Identical logic to "Non-overlapping Intervals" (LeetCode 435).
- Sorting by end time ensures that we close out intervals as quickly as possible, leaving the maximum room for future chains.
 *
- Status: Accepted
 */