/*
- ============================================================
- Problem   : K-Concatenation Maximum Sum
- LeetCode  : https://leetcode.com/problems/k-concatenation-maximum-sum/
- Problem # : 1191
- Difficulty: Medium
- Topic     : Array, Dynamic Programming
 *
- Approach:
- If k = 1, run standard Kadane on the array once.
- If k > 1, the max sum could wrap exactly once (Kadane on arr x2). If the total sum of arr is positive, we can safely add (k-2) * total_sum.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1)
- ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int mod = 1e9 + 7;
    
    long long kadane(vector<int>& arr) {
        long long curr = 0, max_so_far = 0;
        for (int x : arr) {
            curr = max((long long)x, curr + x);
            max_so_far = max(max_so_far, curr);
        }
        return max_so_far;
    }
    
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long max_single = kadane(arr);
        if (k == 1) return max_single % mod;
        
        vector<int> double_arr = arr;
        double_arr.insert(double_arr.end(), arr.begin(), arr.end());
        long long max_double = kadane(double_arr);
        
        long long total_sum = 0;
        for (int x : arr) total_sum += x;
        
        if (total_sum > 0) {
            return (max_double + (k - 2) * total_sum) % mod;
        } else {
            return max_double % mod;
        }
    }
};

/*
- Key Learnings:
- K-concatenations don't require K array duplications. Max sums naturally resolve after wrapping around at most once.
- The use of modulo (1e9 + 7) is critical at the very end to prevent long long overflows on massive 'k' values.
 *
- Status: Accepted
 */