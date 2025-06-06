/*
- ============================================================
- Problem   : Happy Number
- LeetCode  : https://leetcode.com/problems/happy-number/
- Problem # : 202
- Difficulty: Easy
- Topic     : Math, Two Pointers
 *
- Approach:
- Treat the sum of squared digits as traversing a conceptual Linked List.
- Use fast and slow pointers. If they meet at 1, it's happy. If they meet at any other number, it's caught in an infinite cycle.
 *
- Time Complexity  : O(log n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }
        return totalSum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};

/*
- Key Learnings:
- Fast & Slow pointers aren't just for physical linked lists; they work for any deterministic state machine or mathematical sequence.
- Replacing the Hash Set with O(1) pointers saves memory allocation overhead.
 *
- Status: Accepted
 */