/*
- ============================================================
- Problem   : Implement Stack using Queues
- LeetCode  : https://leetcode.com/problems/implement-stack-using-queues/
- Problem # : 225
- Difficulty: Easy
- Topic     : Stack, Design, Queue
 *
- Approach:
- Use a single queue.
- When pushing a new element, add it to the back, then pop all previous elements from the front and push them back into the queue.
- This immediately puts the newest element at the front, achieving LIFO behavior.
 *
- Time Complexity  : O(n) for push, O(1) for pop
- Space Complexity : O(n)
- ============================================================
 */

#include <queue>

using namespace std;

class MyStack {
    queue<int> q;
    
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/*
- Key Learnings:
- You do not need two queues. Rotating the single queue instantly reverses the access order.
- In system design, choosing whether push or pop is O(N) depends entirely on the expected read/write ratio.
 *
- Status: Accepted
 */