/*
- ============================================================
- Problem   : LRU Cache
- LeetCode  : https://leetcode.com/problems/lru-cache/
- Problem # : 146
- Difficulty: Medium
- Topic     : Hash Table, Linked List, Design
 *
- Approach:
- Combine an unordered_map (for O(1) lookups) with a Doubly Linked List (for O(1) insertions/deletions).
- Map stores {key, Node*}. Most recently used nodes are moved to the front (head). Least recently used drop out the back (tail) when capacity is hit.
 *
- Time Complexity  : O(1) for get and put
- Space Complexity : O(capacity)
- ============================================================
 */

#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, DLinkedNode*> cache;
    int size;
    int capacity;
    DLinkedNode* head;
    DLinkedNode* tail;

    void addNode(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        DLinkedNode* prev = node->prev;
        DLinkedNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addNode(node);
    }

    DLinkedNode* popTail() {
        DLinkedNode* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            DLinkedNode* newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addNode(newNode);
            size++;
            if (size > capacity) {
                DLinkedNode* tail = popTail();
                cache.erase(tail->key);
                delete tail;
                size--;
            }
        }
    }
};

/*
- Key Learnings:
- The standard library list (std::list) can be used, but implementing a custom Doubly Linked List is expected in interviews to show mastery of pointers.
- Dummy head and dummy tail drastically simplify node insertion and deletion logic by eliminating null-pointer edge cases.
 *
- Status: Accepted
 */