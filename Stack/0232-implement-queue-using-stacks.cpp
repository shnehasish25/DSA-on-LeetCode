/*
- ============================================================
- Problem   : Implement Queue using Stacks
- LeetCode  : https://leetcode.com/problems/implement-queue-using-stacks/
- Problem # : 232
- Difficulty: Easy
- Topic     : Stack, Design
 *
- Approach:
- Use two stacks: 'input' and 'output'.
- Push all new elements to 'input'.
- For pop/peek operations, if 'output' is empty, dump everything from 'input' into 'output'. This reverses the order, turning LIFO into FIFO.
 *
- Time Complexity  : Amortized O(1) for pop/peek, O(1) for push
- Space Complexity : O(n)
- ============================================================
 */

#include <stack>

using namespace std;

class MyQueue {
    stack<int> input, output;
    
public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/*
- Key Learnings:
- The "lazy transfer" from input to output guarantees amortized O(1) time because each element is moved exactly twice (once in, once out) over its entire lifespan.
 *
- Status: Accepted
 */