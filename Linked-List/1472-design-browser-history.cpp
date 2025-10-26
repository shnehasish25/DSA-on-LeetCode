/*
- ============================================================
- Problem   : Design Browser History
- LeetCode  : https://leetcode.com/problems/design-browser-history/
- Problem # : 1472
- Difficulty: Medium
- Topic     : Linked List, Design, Doubly-Linked List, Stack
 *
- Approach:
- Implement a custom Doubly Linked List.
- When visiting a new url, clear all forward history (sever the 'next' pointer) and append the new node.
- 'Back' and 'Forward' operations are simple pointer traversals up to a maximum step limit.
 *
- Time Complexity  : O(1) for visit, O(steps) for back/forward
- Space Complexity : O(n)
- ============================================================
 */

#include <string>

using namespace std;

class BrowserHistory {
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(nullptr), next(nullptr) {}
    };
    
    Node* curr;

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        while (curr->prev && steps > 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/*
- Key Learnings:
- A browser history tree is the perfect real-world application of a Doubly Linked List.
- Clearing forward history is extremely efficient; we just let go of the pointers (in a real C++ system, we would iterate and 'delete' the severed nodes to prevent memory leaks).
 *
- Status: Accepted
 */