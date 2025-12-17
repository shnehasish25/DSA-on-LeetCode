/*
- ============================================================
- Problem   : Data Stream as Disjoint Intervals
- LeetCode  : https://leetcode.com/problems/data-stream-as-disjoint-intervals/
- Problem # : 352
- Difficulty: Hard
- Topic     : Binary Search, Design, Ordered Set
 *
- Approach:
- Use a std::map (which acts as a balanced BST) mapping the 'start' of an interval to its 'end'.
- Upon adding a number, check adjacent intervals (using upper_bound) to see if it merges with the previous interval, the next interval, or both.
 *
- Time Complexity  : O(log n) per addNum, O(n) per getIntervals
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SummaryRanges {
    map<int, int> intervals;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        auto it = intervals.upper_bound(value);
        
        bool merge_left = false, merge_right = false;
        
        auto prev_it = it;
        if (it != intervals.begin()) {
            prev_it--;
            if (prev_it->second >= value) return; // Already covered
            if (prev_it->second + 1 == value) merge_left = true;
        }
        
        if (it != intervals.end() && it->first == value + 1) {
            merge_right = true;
        }
        
        if (merge_left && merge_right) {
            prev_it->second = it->second;
            intervals.erase(it);
        } else if (merge_left) {
            prev_it->second = value;
        } else if (merge_right) {
            int end = it->second;
            intervals.erase(it);
            intervals[value] = end;
        } else {
            intervals[value] = value;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto const& [start, end] : intervals) {
            res.push_back({start, end});
        }
        return res;
    }
};

/*
- Key Learnings:
- std::map natively handles sorted dynamic intervals. Using upper_bound allows fast lookup of the neighboring intervals.
- The 4 states of insertion (cover both, cover left, cover right, cover neither) represent universal logic for all dynamic disjoint datasets.
 *
- Status: Accepted
 */