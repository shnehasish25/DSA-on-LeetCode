/*
- ============================================================
- Problem   : Merge Sorted Array
- LeetCode  : https://leetcode.com/problems/merge-sorted-array/
- Problem # : 88
- Difficulty: Easy
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Utilize the empty space at the end of nums1 by using three pointers: one at the end of valid elements in nums1, one at the end of nums2, and one at the very end of nums1.
- Compare elements backwards, placing the larger one at the back of nums1 to avoid overwriting unmerged data.
 *
- Time Complexity  : O(m + n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;       // Pointer for valid elements in nums1
        int p2 = n - 1;       // Pointer for nums2
        int p = m + n - 1;    // Pointer for placing elements at the end of nums1
        
        // 1. Compare from the back to the front
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // 2. If nums2 still has elements left, copy them over
        // (If nums1 has elements left, they are already in the correct place)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};

/*
- Key Learnings:
- When modifying an array in-place where elements need to be shifted, always see if iterating backwards prevents data overwriting.
- Three pointers give you exact control over two source arrays and one destination array simultaneously.
 *
- Status: Accepted
 */