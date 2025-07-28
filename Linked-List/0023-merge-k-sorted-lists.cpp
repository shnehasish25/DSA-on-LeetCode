/*
- ============================================================
- Problem   : Merge k Sorted Lists
- LeetCode  : https://leetcode.com/problems/merge-k-sorted-lists/
- Problem # : 23
- Difficulty: Hard
- Topic     : Linked List, Divide and Conquer, Heap (Priority Queue)
 *
- Approach:
- Use a Min-Heap (priority_queue) to keep track of the smallest current element across all 'k' lists.
- Pop the smallest, append to result, and if the popped node has a 'next', push the next node into the heap.
 *
- Time Complexity  : O(N log k) where N is total nodes
- Space Complexity : O(k) for the priority queue
- ============================================================
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
        
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();
            
            tail->next = curr;
            tail = tail->next;
            
            if (curr->next != nullptr) {
                minHeap.push(curr->next);
            }
        }
        
        return dummy.next;
    }
};

/*
- Key Learnings:
- C++ priority_queue requires a custom comparator struct to sort custom objects (like ListNodes).
- The heap size never exceeds 'k', providing extreme memory efficiency compared to dumping all values into a massive array.
 *
- Status: Accepted
 */