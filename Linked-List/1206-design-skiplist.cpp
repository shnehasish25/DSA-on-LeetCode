/*
- ============================================================
- Problem   : Design Skiplist
- LeetCode  : https://leetcode.com/problems/design-skiplist/
- Problem # : 1206
- Difficulty: Hard
- Topic     : Linked List, Design, Randomized
 *
- Approach:
- A Skiplist is a multi-level linked list. The lowest level contains all elements.
- Higher levels act as "express lanes". Nodes are elevated to higher levels based on a coin flip (50% probability).
- Searching starts at the top-left and moves right while the next node is smaller, then drops down a level.
 *
- Time Complexity  : Expected O(log n) for search, add, erase. Worst case O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <cstdlib>

using namespace std;

class Skiplist {
    struct Node {
        int val;
        vector<Node*> next; // Pointers to the next node at various levels
        Node(int v, int levels) : val(v), next(levels, nullptr) {}
    };
    
    Node* head;
    int max_level = 16; // Capped max level
    double p = 0.5;

    int randomLevel() {
        int lvl = 1;
        while ((rand() % 100) < (p * 100) && lvl < max_level) {
            lvl++;
        }
        return lvl;
    }

public:
    Skiplist() {
        head = new Node(-1, max_level); // Dummy head
    }
    
    bool search(int target) {
        Node* curr = head;
        for (int i = max_level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < target) {
                curr = curr->next[i];
            }
        }
        curr = curr->next[0];
        return curr && curr->val == target;
    }
    
    void add(int num) {
        vector<Node*> update(max_level, nullptr);
        Node* curr = head;
        
        for (int i = max_level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }
        
        int lvl = randomLevel();
        Node* newNode = new Node(num, lvl);
        
        for (int i = 0; i < lvl; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<Node*> update(max_level, nullptr);
        Node* curr = head;
        
        for (int i = max_level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }
        
        curr = curr->next[0];
        if (!curr || curr->val != num) return false;
        
        for (int i = 0; i < max_level; i++) {
            if (update[i]->next[i] != curr) break;
            update[i]->next[i] = curr->next[i];
        }
        
        delete curr;
        return true;
    }
};

/*
- Key Learnings:
- Skiplists are the randomized, Linked List equivalent of Balanced Binary Search Trees (like Red-Black Trees).
- The 'update' vector acts exactly like a stack, remembering where we "dropped down" a level so we can wire up new pointers.
 *
- Status: Accepted
 */