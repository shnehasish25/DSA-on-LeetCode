/*
- ============================================================
- Problem   : Verify Preorder Serialization of a Binary Tree
- LeetCode  : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
- Problem # : 331
- Difficulty: Medium
- Topic     : String, Stack, Tree
 *
- Approach:
- Track "slots" (capacity). We start with 1 slot for the root.
- For each node in the serialization: it consumes 1 slot. If slots fall below 0, it is invalid.
- If the node is not a null-marker ('#'), it creates 2 new slots for its children.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        stringstream ss(preorder);
        string node;
        
        while (getline(ss, node, ',')) {
            slots--; // Every node consumes one slot
            
            if (slots < 0) return false; // More nodes than available slots
            
            if (node != "#") {
                slots += 2; // Non-null nodes create 2 new slots
            }
        }
        
        return slots == 0; // Tree is perfectly filled if 0 slots remain
    }
};

/*
- Key Learnings:
- Though solvable with a Stack that collapses "num, #, #" into "#", tracking out-degree capacity (slots) reduces space from O(N) to O(1).
- Out-degree math natively validates the topological structure of any complete tree.
 *
- Status: Accepted
 */