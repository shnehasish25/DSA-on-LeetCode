/*
- ============================================================
- Problem   : My Calendar II
- LeetCode  : https://leetcode.com/problems/my-calendar-ii/
- Problem # : 731
- Difficulty: Medium
- Topic     : Array, Binary Search, Design, Segment Tree
 *
- Approach:
- Keep two lists: one for all bookings, and one specifically for double bookings (overlaps).
- For a new event, first check if it overlaps with any double booking. If it does, a triple booking would occur (return false).
- If safe, add the overlaps of the new event with existing bookings to the double bookings list, then add the event to the main list.
 *
- Time Complexity  : O(n) per booking
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class MyCalendarTwo {
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> double_bookings;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (const auto& db : double_bookings) {
            if (start < db.second && end > db.first) {
                return false; // Triple booking
            }
        }
        
        for (const auto& b : bookings) {
            if (start < b.second && end > b.first) {
                double_bookings.push_back({max(start, b.first), min(end, b.second)});
            }
        }
        
        bookings.push_back({start, end});
        return true;
    }
};

/*
- Key Learnings:
- The intersection of two intervals [start1, end1] and [start2, end2] is always [max(start1, start2), min(end1, end2)].
- Separating state constraints (double vs single overlaps) avoids needing a complex Segment Tree.
 *
- Status: Accepted
 */