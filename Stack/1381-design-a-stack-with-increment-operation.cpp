/*
- ============================================================
- Problem   : Design a Stack With Increment Operation
- LeetCode  : https://leetcode.com/problems/design-a-stack-with-increment-operation/
- Problem # : 1381
- Difficulty: Medium
- Topic     : Stack, Design, Array
 *
- Approach:
- Use a vector to simulate the stack and a parallel array for lazy increments.
- When increment(k, val) is called, only add 'val' to the k-th element's lazy increment slot.
- When popping, add the lazy increment to the popped value, and pass the lazy increment down to the element below it.
 *
- Time Complexity  : O(1) for all operations
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class CustomStack {
    vector<int> st;
    vector<int> inc;
    int maxSize;
    
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        int i = st.size() - 1;
        if (i < 0) return -1;
        
        if (i > 0) {
            inc[i - 1] += inc[i]; // Cascade lazy increment downward
        }
        
        int res = st[i] + inc[i];
        st.pop_back();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)st.size()) - 1;
        if (i >= 0) {
            inc[i] += val;
        }
    }
};

/*
- Key Learnings:
- The "Lazy Propagation" pattern from Segment Trees can be applied directly to Stacks for O(1) range updates.
- By cascading the increment downwards on pop, the lower elements correctly inherit bulk modifications.
 *
- Status: Accepted
 */