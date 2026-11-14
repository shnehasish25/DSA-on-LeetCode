/*
- ============================================================
- Problem   : Boats to Save People
- LeetCode  : https://leetcode.com/problems/boats-to-save-people/
- Problem # : 881
- Difficulty: Medium
- Topic     : Array, Two Pointers, Greedy, Sorting
 *
- Approach:
- Sort weights. Place a pointer at the lightest and heaviest person.
- If the lightest + heaviest fit in a boat, take both (move both pointers). Otherwise, the heaviest goes alone (move right pointer).
 *
- Time Complexity  : O(n log n)
- Space Complexity : O(1)
- ============================================================
 */

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++; 
            }
            right--; // The heaviest person always gets on a boat
            boats++;
        }
        return boats;
    }
};

/*
- Key Learnings:
- The Two Pointer paradigm on a sorted array works brilliantly for pairing problems constrained by maximum capacities.
- We don't have to literally 'build' the pairs; counting the operations gives the result immediately.
 *
- Status: Accepted
 */