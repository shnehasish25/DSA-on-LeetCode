/*
- ============================================================
- Problem   : Minimum Cost Tree From Leaf Values
- LeetCode  : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
- Problem # : 1130
- Difficulty: Medium
- Topic     : Stack, Greedy, Monotonic Stack
 *
- Approach:
- A node is removed by paying the cost of (node * min(left_neighbor, right_neighbor)).
- Maintain a monotonic decreasing stack. When a larger element arrives, pop the smaller elements, calculate their cost using the minimum of the new element or the next element below it in the stack.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> st;
        st.push(INT_MAX); // Dummy anchor to avoid empty checks
        
        for (int num : arr) {
            while (st.top() <= num) {
                int drop = st.top();
                st.pop();
                res += drop * min(st.top(), num);
            }
            st.push(num);
        }
        
        while (st.size() > 2) {
            int drop = st.top();
            st.pop();
            res += drop * st.top();
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Though presented as a Tree/DP problem, this is natively solved by Greedily removing the smallest elements possible, forming a valley.
- INT_MAX acts as the perfect infinitely tall wall to bounce against.
 *
- Status: Accepted
 */