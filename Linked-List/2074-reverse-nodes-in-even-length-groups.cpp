/*
- ============================================================
- Problem   : Reverse Nodes in Even Length Groups
- LeetCode  : https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
- Problem # : 2074
- Difficulty: Medium
- Topic     : Linked List
 *
- Approach:
- Target group lengths increment by 1 (1, 2, 3...). 
- Traverse to count the ACTUAL nodes remaining in the group (it might be cut short at the end of the list).
- If the actual length is even, perform a standard linked list reversal on that subsegment. Otherwise, just skip past it.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev_tail = nullptr;
        ListNode* curr = head;
        int group_len = 1;
        
        while (curr) {
            // 1. Count actual nodes available for this group
            int count = 0;
            ListNode* tracer = curr;
            while (count < group_len && tracer) {
                tracer = tracer->next;
                count++;
            }
            
            // 2. If length is even, reverse it
            if (count % 2 == 0) {
                ListNode* rev_prev = nullptr;
                ListNode* rev_curr = curr;
                ListNode* nextNode = nullptr;
                
                for (int i = 0; i < count; i++) {
                    nextNode = rev_curr->next;
                    rev_curr->next = rev_prev;
                    rev_prev = rev_curr;
                    rev_curr = nextNode;
                }
                
                // curr is now the tail of the reversed group
                prev_tail->next = rev_prev;
                curr->next = rev_curr;
                prev_tail = curr;
                curr = rev_curr;
            } 
            // 3. If odd, just skip past it
            else {
                for (int i = 0; i < count; i++) {
                    prev_tail = curr;
                    curr = curr->next;
                }
            }
            
            group_len++;
        }
        
        return head;
    }
};

/*
- Key Learnings:
- The actual count at the tail end overrides the target group length, making a preview scan ('tracer') strictly necessary.
- Stitching sub-reversals requires maintaining a 'prev_tail' pointer anchoring the end of the previous group.
 *
- Status: Accepted
 */