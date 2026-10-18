/*
- ============================================================
- Problem   : Maximum Frequency Stack
- LeetCode  : https://leetcode.com/problems/maximum-frequency-stack/
- Problem # : 895
- Difficulty: Hard
- Topic     : Hash Table, Stack, Design
 *
- Approach:
- Use a hash map to track the exact frequency of each element.
- Use a second hash map mapping 'frequency' to a 'Stack of elements'.
- When pushing, increment freq, and push the element onto the stack corresponding to its new freq. Track global max_freq.
- When popping, pop from the stack at max_freq. If that stack becomes empty, decrement max_freq.
 *
- Time Complexity  : O(1) for push and pop
- Space Complexity : O(n)
- ============================================================
 */

#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int max_freq;
    
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int val = group[max_freq].top();
        group[max_freq].pop();
        
        freq[val]--;
        
        if (group[max_freq].empty()) {
            max_freq--;
        }
        
        return val;
    }
};

/*
- Key Learnings:
- By pushing the same element to layer 1, layer 2, and layer 3 stacks, we preserve the exact chronological insertion order for ties at every frequency level!
- This multi-layered stack architecture gives O(1) pops without needing a priority queue.
 *
- Status: Accepted
 */