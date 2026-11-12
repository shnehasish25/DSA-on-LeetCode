/*
- ============================================================
- Problem   : Intersection of Two Arrays II
- LeetCode  : https://leetcode.com/problems/intersection-of-two-arrays-ii/
- Problem # : 350
- Difficulty: Easy
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Similar to 349, sort both arrays and use two pointers.
- Since we want all duplicate intersections, just append matches without checking the previous insertion.
 *
- Time Complexity  : O(n log n + m log m)
- Space Complexity : O(1) (excluding result)
- ============================================================
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int p1 = 0, p2 = 0;
        
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums1[p1]);
                p1++; p2++;
            } else if (nums1[p1] < nums2[p2]) {
                p1++;
            } else {
                p2++;
            }
        }
        return res;
    }
};

/*
- Key Learnings:
- This is the classic "Merge" step logic from Merge Sort applied to finding commonalities.
- Extremely space-efficient for very large datasets where Hash Maps would exceed memory limits.
 *
- Status: Accepted
 */