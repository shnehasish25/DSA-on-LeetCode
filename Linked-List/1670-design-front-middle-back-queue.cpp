/*
- ============================================================
- Problem   : Design Front Middle Back Queue
- LeetCode  : https://leetcode.com/problems/design-front-middle-back-queue/
- Problem # : 1670
- Difficulty: Medium
- Topic     : Linked List, Design
 *
- Approach:
- Use two C++ std::deque (double-ended queues) to represent the front half and back half of the elements.
- Keep the deques balanced: 'front' should equal 'back' in size, or 'front' can have 1 less element if total is odd (meaning 'back' holds the exact middle element at its front).
- Rebalance after every insertion or deletion.
 *
- Time Complexity  : O(1) for all operations
- Space Complexity : O(n)
- ============================================================
 */

#include <deque>

using namespace std;

class FrontMiddleBackQueue {
    deque<int> front;
    deque<int> back;
    
    void balance() {
        if (front.size() > back.size()) {
            back.push_front(front.back());
            front.pop_back();
        } else if (back.size() > front.size() + 1) {
            front.push_back(back.front());
            back.pop_front();
        }
    }
    
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        front.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if (front.size() < back.size()) {
            front.push_back(val);
        } else {
            back.push_front(val);
        }
        balance();
    }
    
    void pushBack(int val) {
        back.push_back(val);
        balance();
    }
    
    int popFront() {
        if (front.empty() && back.empty()) return -1;
        int val;
        if (front.empty()) {
            val = back.front();
            back.pop_front();
        } else {
            val = front.front();
            front.pop_front();
        }
        balance();
        return val;
    }
    
    int popMiddle() {
        if (front.empty() && back.empty()) return -1;
        int val;
        if (front.size() == back.size()) {
            val = front.back();
            front.pop_back();
        } else {
            val = back.front();
            back.pop_front();
        }
        balance();
        return val;
    }
    
    int popBack() {
        if (front.empty() && back.empty()) return -1;
        int val = back.back();
        back.pop_back();
        balance();
        return val;
    }
};

/*
- Key Learnings:
- Splitting a list into two distinct deques is the standard architecture for O(1) middle-access operations.
- The 'balance()' function acts as the singular source of truth, preventing fragmented edge cases from leaking into the individual pop/push functions.
 *
- Status: Accepted
 */