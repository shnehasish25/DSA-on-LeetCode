/*
- ============================================================
- Problem   : Min Stack
- LeetCode  : https://leetcode.com/problems/min-stack/
- Problem # : 155
- Difficulty: Medium
- Topic     : Stack, Design
 *
- Approach:
- Use a single stack storing pairs of integers: {actual_value, current_minimum}.
- When pushing a new value, the new current_minimum is the minimum of the new value and the previous current_minimum.
 *
- Time Complexity  : O(1) for all operations
- Space Complexity : O(n)
- ============================================================
 */

#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st; // {value, min_so_far}
    
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/*
- Key Learnings:
- Coupling the state (the minimum value at that exact moment in time) with the element itself completely eliminates the need to recalculate minimums when elements are popped.
- Using std::pair keeps the data tightly bound and cache-friendly.
 *
- Status: Accepted
 */