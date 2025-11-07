/*
- ============================================================
- Problem   : Add Two Polynomials Represented as Linked Lists (Premium)
- LeetCode  : https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/
- Problem # : 1634
- Difficulty: Medium
- Topic     : Linked List, Math, Two Pointers
 *
- Approach:
- Use two pointers to merge the lists based on the 'power' of the polynomial terms.
- If powers match, add their coefficients. Only append the new term if the resulting coefficient is non-zero.
- If one power is greater, append it and advance that specific pointer.
 *
- Time Complexity  : O(n + m)
- Space Complexity : O(1) excluding output list
- ============================================================
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummy;
        PolyNode* tail = &dummy;
        
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                tail->next = new PolyNode(poly1->coefficient, poly1->power);
                poly1 = poly1->next;
                tail = tail->next;
            } else if (poly1->power < poly2->power) {
                tail->next = new PolyNode(poly2->coefficient, poly2->power);
                poly2 = poly2->next;
                tail = tail->next;
            } else {
                int sum = poly1->coefficient + poly2->coefficient;
                if (sum != 0) {
                    tail->next = new PolyNode(sum, poly1->power);
                    tail = tail->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        
        while (poly1) {
            tail->next = new PolyNode(poly1->coefficient, poly1->power);
            poly1 = poly1->next;
            tail = tail->next;
        }
        
        while (poly2) {
            tail->next = new PolyNode(poly2->coefficient, poly2->power);
            poly2 = poly2->next;
            tail = tail->next;
        }
        
        return dummy.next;
    }
};

/*
- Key Learnings:
- This is a direct variation of "Merge Two Sorted Lists".
- The only twist is merging values when the sorting key (power) is identical, and dropping nodes entirely if their sum cancels out to 0.
 *
- Status: Accepted
 */