/*
- ============================================================
- Problem   : Split Linked List in Parts
- LeetCode  : https://leetcode.com/problems/split-linked-list-in-parts/
- Problem # : 725
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- First, find the total length of the linked list.
- Calculate the base size of each part (length / k) and the number of parts that get an extra node (length % k).
- Iterate and sever the list into the computed parts.
 *
- Time Complexity  : O(n + k)
- Space Complexity : O(k) for the result array
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        int part_size = length / k;
        int extra = length % k;
        
        vector<ListNode*> res(k, nullptr);
        curr = head;
        
        for (int i = 0; i < k && curr; i++) {
            res[i] = curr;
            int current_part_size = part_size + (extra > 0 ? 1 : 0);
            extra--;
            
            for (int j = 0; j < current_part_size - 1; j++) {
                curr = curr->next;
            }
            
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Precomputing the length allows exact mathematical division of nodes. 
- Nullifying the tail of each chunk (curr->next = nullptr) is crucial to actually break the list apart.
 *
- Status: Accepted
 */