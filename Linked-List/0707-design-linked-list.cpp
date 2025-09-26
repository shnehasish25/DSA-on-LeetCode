/*
- ============================================================
- Problem   : Design Linked List
- LeetCode  : https://leetcode.com/problems/design-linked-list/
- Problem # : 707
- Difficulty: Medium
- Topic     : Linked List, Design
 *
- Approach:
- Implement a standard Singly Linked List with a dummy head and a size variable.
- Tracking 'size' prevents out-of-bounds traversals instantly.
 *
- Time Complexity  : O(1) for head insertions, O(n) for index/tail
- Space Complexity : O(n)
- ============================================================
 */

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = new Node(0); // Dummy node
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head->next;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        
        Node* curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        size--;
    }
};

/*
- Key Learnings:
- The presence of a 'size' integer makes validating inputs trivial.
- By routing addAtHead and addAtTail through addAtIndex, you adhere to the DRY (Don't Repeat Yourself) principle and avoid duplicate pointer logic.
 *
- Status: Accepted
 */