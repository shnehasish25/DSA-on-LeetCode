/*
- ============================================================
- Problem   : Interval List Intersections
- LeetCode  : https://leetcode.com/problems/interval-list-intersections/
- Problem # : 986
- Difficulty: Medium
- Topic     : Array, Two Pointers
 *
- Approach:
- Use two pointers, one for each list.
- An intersection exists if max(start1, start2) <= min(end1, end2). If so, push the overlapping range.
- Advance the pointer of the interval that ends earliest, as it cannot intersect with anything else.
 *
- Time Complexity  : O(m + n)
- Space Complexity : O(1) excluding output array
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            
            if (start <= end) {
                res.push_back({start, end});
            }
            
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The intersection of two valid intervals is universally represented by [max(start1, start2), min(end1, end2)].
- Discarding the interval with the smaller end time ensures we don't miss valid overlaps, effectively merging Two Pointers with Intervals.
 *
- Status: Accepted
 */