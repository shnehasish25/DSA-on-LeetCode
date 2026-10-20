/*
- ============================================================
- Problem   : Validate Stack Sequences
- LeetCode  : https://leetcode.com/problems/validate-stack-sequences/
- Problem # : 946
- Difficulty: Medium
- Topic     : Array, Stack, Simulation
 *
- Approach:
- Simulate the process. Push elements from the 'pushed' array one by one into a stack.
- After every push, greedily pop from the stack as long as the top matches the current element in the 'popped' array.
- Return true if the stack is completely empty at the end.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pop_idx = 0;
        
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && st.top() == popped[pop_idx]) {
                st.pop();
                pop_idx++;
            }
        }
        
        return st.empty();
    }
};

/*
- Key Learnings:
- Stack validation problems rarely need complex analytical math. Pure simulation guarantees verification.
- The inner greedy while loop executes exactly as a real parser would.
 *
- Status: Accepted
 */