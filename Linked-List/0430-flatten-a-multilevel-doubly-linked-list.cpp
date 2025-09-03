/*
- ============================================================
- Problem   : Flatten a Multilevel Doubly Linked List
- LeetCode  : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
- Problem # : 430
- Difficulty: Medium
- Topic     : Linked List, Depth-First Search
 *
- Approach:
- Traverse iteratively. If a node has a 'child', find the tail of that child list.
- Splice the child list between the current node and its original 'next' node. Nullify the child pointer.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childList = curr->child;
                
                // Find tail of child
                Node* tail = childList;
                while (tail->next) {
                    tail = tail->next;
                }
                
                // Connect current to child
                curr->next = childList;
                childList->prev = curr;
                curr->child = nullptr;
                
                // Connect tail of child to nextNode
                tail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = tail;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};

/*
- Key Learnings:
- Iterative splicing guarantees O(1) space. A recursive approach would cost O(n) space on the call stack.
- You must remember to nullify the 'child' pointer after elevating the child list to the main level.
 *
- Status: Accepted
 */