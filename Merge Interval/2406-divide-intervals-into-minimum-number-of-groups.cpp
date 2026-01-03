/*
- ============================================================
- Problem   : Divide Intervals Into Minimum Number of Groups
- LeetCode  : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
- Problem # : 2406
- Difficulty: Medium
- Topic     : Array, Two Pointers, Greedy, Sorting
 *
- Approach:
- Exactly like "Meeting Rooms II".
- Separate start and end times into two arrays and sort them.
- Use two pointers to count overlapping active intervals. The maximum overlap at any point dictates the minimum groups needed.
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (const auto& i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int max_groups = 0, current_groups = 0;
        int s = 0, e = 0, n = intervals.size();
        
        while (s < n) {
            // Include equality because intersecting at endpoints counts as overlapping in this problem
            if (starts[s] <= ends[e]) {
                current_groups++;
                s++;
            } else {
                current_groups--;
                e++;
            }
            max_groups = max(max_groups, current_groups);
        }
        
        return max_groups;
    }
};

/*
- Key Learnings:
- "Divide intervals into non-overlapping groups" is the exact same premise as "How many meeting rooms do we need".
- The only difference from Meeting Rooms II is that start <= end counts as an overlap in this specific problem definition.
 *
- Status: Accepted
 */