/*
- ============================================================
- Problem   : All O`one Data Structure
- LeetCode  : https://leetcode.com/problems/all-oone-data-structure/
- Problem # : 432
- Difficulty: Hard
- Topic     : Hash Table, Linked List, Design
 *
- Approach:
- Use a Doubly Linked List of "Buckets". Each bucket holds a set of strings that share the exact same count.
- Keep the buckets strictly sorted by count. When a string increments, move it to the next bucket (creating it if it doesn't exist).
- MaxKey is the tail bucket's string, MinKey is the head bucket's string.
 *
- Time Complexity  : O(1) for all operations
- Space Complexity : O(n)
- ============================================================
 */

#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>

using namespace std;

class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };
    
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;

public:
    AllOne() {}
    
    void inc(string key) {
        if (!bucketOfKey.count(key)) {
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front({1, {}});
            }
            buckets.front().keys.insert(key);
            bucketOfKey[key] = buckets.begin();
        } else {
            auto curBucket = bucketOfKey[key];
            auto nextBucket = next(curBucket);
            
            if (nextBucket == buckets.end() || nextBucket->count != curBucket->count + 1) {
                nextBucket = buckets.insert(nextBucket, {curBucket->count + 1, {}});
            }
            nextBucket->keys.insert(key);
            bucketOfKey[key] = nextBucket;
            
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
        }
    }
    
    void dec(string key) {
        auto curBucket = bucketOfKey[key];
        
        if (curBucket->count == 1) {
            bucketOfKey.erase(key);
        } else {
            auto prevBucket = prev(curBucket);
            if (curBucket == buckets.begin() || prevBucket->count != curBucket->count - 1) {
                prevBucket = buckets.insert(curBucket, {curBucket->count - 1, {}});
            }
            prevBucket->keys.insert(key);
            bucketOfKey[key] = prevBucket;
        }
        
        curBucket->keys.erase(key);
        if (curBucket->keys.empty()) buckets.erase(curBucket);
    }
    
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.back().keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.front().keys.begin());
    }
};

/*
- Key Learnings:
- Linking frequency buckets together dynamically ensures O(1) lookup of min/max values without priority queues.
- This is fundamentally an evolution of the LFU Cache architecture.
 *
- Status: Accepted
 */