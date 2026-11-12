/*
- ============================================================
- Problem   : Intersection of Two Arrays
- LeetCode  : https://leetcode.com/problems/intersection-of-two-arrays/
- Problem # : 349
- Difficulty: Easy
- Topic     : Array, Two Pointers, Sorting
 *
- Approach:
- Sort both arrays, then use two pointers starting from index 0 of both.
- If values match, record it (avoiding duplicates) and advance both. Otherwise, advance the pointer with the smaller value.
 *
- Time Complexity  : O(n log n + m log m)
- Space Complexity : O(1) (excluding result)
- ============================================================
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int p1 = 0, p2 = 0;
        
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                if (res.empty() || res.back() != nums1[p1]) {
                    res.push_back(nums1[p1]);
                }
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
- Sorting transforms this from a Hash Map problem into a Two Pointer traversal.
- Checking 'res.back()' before pushing prevents duplicate entries without needing an expensive unordered_set.
 *
- Status: Accepted
 */