/*
- ============================================================
- Problem   : Insert into a Sorted Circular Linked List (Premium)
- LeetCode  : https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
- Problem # : 708
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Traverse the circular list with 'prev' and 'curr'.
- The node can be inserted if:
  1. It fits normally: prev->val <= insertVal <= curr->val
  2. It crosses the min/max boundary (prev->val > curr->val) AND it's either greater than the max or less than the min.
- If we traverse the whole circle without inserting (e.g., all values are identical), just insert anywhere.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != head) { // Traverse exactly one loop
            if (prev->val <= insertVal && insertVal <= curr->val) {
                break; // Fits securely between two nodes
            }
            if (prev->val > curr->val) { // Boundary between max and min
                if (insertVal >= prev->val || insertVal <= curr->val) {
                    break; 
                }
            }
            prev = curr;
            curr = curr->next;
        }
        
        // Either we broke out at the right spot, or completed a loop (uniform values)
        prev->next = newNode;
        newNode->next = curr;
        
        return head;
    }
};

/*
- Key Learnings:
- Circular lists require a strict stopping condition (curr != head) to prevent infinite traversal.
- The "wrap around" boundary (where prev > curr) is the anchor for values that fall outside the current min and max of the list.
 *
- Status: Accepted
 */