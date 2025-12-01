/*
- ============================================================
- Problem   : Insert Greatest Common Divisors in Linked List
- LeetCode  : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
- Problem # : 2807
- Difficulty: Medium
- Topic     : Linked List, Math
 *
- Approach:
- Traverse the linked list. For every adjacent pair, compute their GCD.
- Create a new node with this GCD and splice it strictly between the two adjacent nodes.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <numeric> // For std::gcd

using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* curr = head;
        while (curr && curr->next) {
            int gcd_val = gcd(curr->val, curr->next->val);
            ListNode* gcdNode = new ListNode(gcd_val);
            
            gcdNode->next = curr->next;
            curr->next = gcdNode;
            
            curr = gcdNode->next; // Skip over the newly inserted node
        }
        
        return head;
    }
};

/*
- Key Learnings:
- Use C++17's built-in std::gcd from the <numeric> library to avoid writing Euclidean algorithms from scratch.
- Always advance 'curr' by two structural steps (or set to gcdNode->next) to prevent infinite loops of processing the newly inserted node.
 *
- Status: Accepted
 */