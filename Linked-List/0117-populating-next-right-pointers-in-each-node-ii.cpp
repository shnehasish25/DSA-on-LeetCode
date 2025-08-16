/*
- ============================================================
- Problem   : Populating Next Right Pointers in Each Node II
- LeetCode  : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
- Problem # : 117
- Difficulty: Medium
- Topic     : Linked List, Tree, BFS
 *
- Approach:
- Unlike a perfect binary tree, nodes might be missing.
- Use a dummy node for the NEXT level to act as an anchor. Iterate through the current level, stringing together any children that exist to the dummy's tail.
- Once the level is done, drop down to dummy->next.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        
        while (curr) {
            Node dummy(0);
            Node* tail = &dummy;
            
            // Traverse the current level and link the children into the next level
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // Move horizontally
            }
            
            // Drop down to the constructed next level
            curr = dummy.next;
        }
        
        return root;
    }
};

/*
- Key Learnings:
- A dummy node on the stack safely and elegantly absorbs the "first child of the next level" edge case without messy if/else tracking.
- This is the ultimate O(1) space Breadth-First Search template.
 *
- Status: Accepted
 */