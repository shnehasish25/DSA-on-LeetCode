/*
- ============================================================
- Problem   : My Calendar I
- LeetCode  : https://leetcode.com/problems/my-calendar-i/
- Problem # : 729
- Difficulty: Medium
- Topic     : Array, Binary Search, Design, Segment Tree
 *
- Approach:
- Store the booked events in a std::set (which automatically keeps them sorted by start time).
- For a new event [start, end), use lower_bound to find the first event that starts at or after our new 'start'.
- Check if it overlaps with the next event or the previous event. If no overlap, insert it.
 *
- Time Complexity  : O(log n) per booking
- Space Complexity : O(n)
- ============================================================
 */

#include <set>
#include <utility>

using namespace std;

class MyCalendar {
    set<pair<int, int>> calendar;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = calendar.lower_bound({start, end});
        
        if (next != calendar.end() && next->first < end) {
            return false;
        }
        if (next != calendar.begin() && prev(next)->second > start) {
            return false;
        }
        
        calendar.insert({start, end});
        return true;
    }
};

/*
- Key Learnings:
- std::set provides an underlying balanced BST (Red-Black Tree), allowing O(log n) insertions and overlap lookups for dynamic intervals.
- Checking both 'next' and 'prev(next)' securely verifies boundaries in an ordered stream.
 *
- Status: Accepted
 */