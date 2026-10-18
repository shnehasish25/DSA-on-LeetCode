/*
- ============================================================
- Problem   : Online Stock Span
- LeetCode  : https://leetcode.com/problems/online-stock-span/
- Problem # : 901
- Difficulty: Medium
- Topic     : Stack, Design, Monotonic Stack
 *
- Approach:
- Use a Monotonic Decreasing Stack storing pairs of {price, span}.
- When a new price arrives, pop all prices smaller than or equal to it, accumulating their spans into the current price's span.
 *
- Time Complexity  : Amortized O(1) per next() call
- Space Complexity : O(n)
- ============================================================
 */

#include <stack>
#include <utility>

using namespace std;

class StockSpanner {
    stack<pair<int, int>> st; // {price, span}
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/*
- Key Learnings:
- The span intrinsically compresses historical data. Instead of keeping a long list of small days, we compress them into a single integer inside the stack pair.
- Pushing {price, span} perfectly preserves the total range coverage even after intermediate days are popped.
 *
- Status: Accepted
 */