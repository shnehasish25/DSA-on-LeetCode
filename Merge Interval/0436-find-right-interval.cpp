/*
- ============================================================
- Problem   : Find Right Interval
- LeetCode  : https://leetcode.com/problems/find-right-interval/
- Problem # : 436
- Difficulty: Medium
- Topic     : Array, Binary Search, Sorting
 *
- Approach:
- Store the start times and their original indices in a separate array, then sort it by start times.
- For each interval's end time, use binary search (lower_bound) on the sorted array to find the first start time that is >= the end time.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start_indices;
        
        for (int i = 0; i < n; i++) {
            start_indices.push_back({intervals[i][0], i});
        }
        
        sort(start_indices.begin(), start_indices.end());
        vector<int> res(n, -1);
        
        for (int i = 0; i < n; i++) {
            int end_target = intervals[i][1];
            
            // Binary search for the first start time >= end_target
            auto it = lower_bound(start_indices.begin(), start_indices.end(), make_pair(end_target, -1));
            
            if (it != start_indices.end()) {
                res[i] = it->second;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Since we need to return original indices, saving them in a vector of pairs before sorting is mandatory.
- std::lower_bound works with pairs; it compares the 'first' element (the start time) automatically.
 *
- Status: Accepted
 */