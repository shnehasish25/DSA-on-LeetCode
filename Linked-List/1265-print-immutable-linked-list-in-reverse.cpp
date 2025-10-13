/*
- ============================================================
- Problem   : Print Immutable Linked List in Reverse (Premium)
- LeetCode  : https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
- Problem # : 1265
- Difficulty: Medium
- Topic     : Linked List, Recursion, Stack
 *
- Approach:
- The list is immutable (we cannot reverse the pointers). 
- Use the call stack via recursion to traverse to the end of the list. As the recursion unwinds, call printValue().
 *
- Time Complexity  : O(n)
- Space Complexity : O(n) for the recursion call stack
- ============================================================
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head != nullptr) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};

/*
- Key Learnings:
- Recursion naturally reverses chronological order because the code *after* the recursive call executes strictly during the unwinding phase.
- An iterative solution would use an explicit std::stack, but recursion is infinitely more elegant here.
 *
- Status: Accepted
 */