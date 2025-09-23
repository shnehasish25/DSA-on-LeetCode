/*
- ============================================================
- Problem   : LFU Cache
- LeetCode  : https://leetcode.com/problems/lfu-cache/
- Problem # : 460
- Difficulty: Hard
- Topic     : Hash Table, Linked List, Design
 *
- Approach:
- Use two Hash Maps: one mapping key -> node (for O(1) access), and one mapping frequency -> Doubly Linked List of nodes (for O(1) eviction).
- Maintain a 'min_freq' variable. When capacity is reached, evict the tail of the list at 'min_freq'.
- When a node is accessed, move it to the list at frequency + 1, and update 'min_freq' if necessary.
 *
- Time Complexity  : O(1) for get and put
- Space Complexity : O(capacity)
- ============================================================
 */

#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
    struct Node {
        int key, value, freq;
    };
    
    int capacity;
    int min_freq;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        if (capacity == 0 || key_table.find(key) == key_table.end()) return -1;
        
        auto node = key_table[key];
        int val = node->value, freq = node->freq;
        
        freq_table[freq].erase(node);
        if (freq_table[freq].empty() && min_freq == freq) {
            min_freq++;
        }
        
        freq_table[freq + 1].push_front({key, val, freq + 1});
        key_table[key] = freq_table[freq + 1].begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (key_table.find(key) != key_table.end()) {
            auto node = key_table[key];
            node->value = value; // Update value
            get(key);            // Trigger frequency update
            return;
        }
        
        if (key_table.size() == capacity) {
            auto evict_node = freq_table[min_freq].back();
            key_table.erase(evict_node.key);
            freq_table[min_freq].pop_back();
        }
        
        min_freq = 1;
        freq_table[1].push_front({key, value, 1});
        key_table[key] = freq_table[1].begin();
    }
};

/*
- Key Learnings:
- Grouping nodes by frequency using a Hash Map of Doubly Linked Lists is the master pattern for LFU.
- C++ std::list provides O(1) insertion/deletion anywhere if you have the iterator, making it perfect for custom caches.
 *
- Status: Accepted
 */