/*
- ============================================================
- Problem   : Subarray Sums Divisible by K
- LeetCode  : https://leetcode.com/problems/subarray-sums-divisible-by-k/
- Problem # : 974
- Difficulty: Medium
- Topic     : Array, Hash Table, Prefix Sum
 *
- Approach:
- Track the frequencies of the running prefix sum modulo k.
- Every time you see a remainder, add its past occurrences to the count, then increment the frequency.
 *
- Time Complexity  : O(n)
- Space Complexity : O(k)
- ============================================================
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> rem_counts;
        rem_counts[0] = 1;
        
        int current_sum = 0, count = 0;
        
        for (int num : nums) {
            current_sum += num;
            int remainder = current_sum % k;
            
            // C++ allows negative remainders. Force it to be positive mathematical modulo.
            if (remainder < 0) remainder += k;
            
            if (rem_counts.find(remainder) != rem_counts.end()) {
                count += rem_counts[remainder];
            }
            
            rem_counts[remainder]++;
        }
        
        return count;
    }
};

/*
- Key Learnings:
- Extremely similar to 523, but instead of tracking the index to check length, we track the count to find all combinations.
- C++ handles modulo of negative numbers differently than Python. Always use '(rem % k + k) % k' or 'if (rem < 0) rem += k' to fix it.
 *
- Status: Accepted
 */