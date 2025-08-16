/*
- ============================================================
- Problem   : Copy List with Random Pointer
- LeetCode  : https://leetcode.com/problems/copy-list-with-random-pointer/
- Problem # : 138
- Difficulty: Medium
- Topic     : Hash Table, Linked List
 *
- Approach:
- Use a Hash Map to map original nodes to their cloned counterparts.
- Pass 1: Create all cloned nodes and populate the map.
- Pass 2: Link 'next' and 'random' pointers of the cloned nodes using the map references.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <unordered_map>

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> cloneMap;
        Node* curr = head;
        
        while (curr) {
            cloneMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            cloneMap[curr]->next = cloneMap[curr->next];
            cloneMap[curr]->random = cloneMap[curr->random];
            curr = curr->next;
        }
        
        return cloneMap[head];
    }
};

/*
- Key Learnings:
- A hash map creates an instant O(1) bridge between original memory addresses and newly allocated memory addresses.
- (Note: An O(1) space variant exists by weaving cloned nodes physically into the original list, but the Hash Map is standard for production readability).
 *
- Status: Accepted
 */