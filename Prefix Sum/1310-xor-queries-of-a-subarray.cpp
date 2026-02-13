/*
- ============================================================
- Problem   : XOR Queries of a Subarray
- LeetCode  : https://leetcode.com/problems/xor-queries-of-a-subarray/
- Problem # : 1310
- Difficulty: Medium
- Topic     : Array, Bit Manipulation, Prefix Sum
 *
- Approach:
- XOR has a self-canceling property: A ^ A = 0.
- Build a Prefix XOR array. To find the XOR sum from L to R, compute prefix[R + 1] ^ prefix[L].
 *
- Time Complexity  : O(n + q)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        vector<int> res;
        for (const auto& q : queries) {
            res.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Prefix XOR works identically to Prefix Sum, but subtraction (-) is replaced by the XOR operator (^) due to its inverse property.
- Padding the prefix array with a leading 0 prevents out-of-bounds checks for queries starting at index 0.
 *
- Status: Accepted
 */