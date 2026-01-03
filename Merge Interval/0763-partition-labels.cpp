/*
- ============================================================
- Problem   : Partition Labels
- LeetCode  : https://leetcode.com/problems/partition-labels/
- Problem # : 763
- Difficulty: Medium
- Topic     : Hash Table, Two Pointers, String, Greedy
 *
- Approach:
- Store the last occurrence index of every character.
- Iterate the string, updating the end of the current partition to be the max last occurrence of the characters seen so far.
- If the current index reaches this 'end', a partition is successfully closed.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (26 characters)
- ============================================================
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_seen(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last_seen[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int max_end = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            max_end = max(max_end, last_seen[s[i] - 'a']);
            
            if (i == max_end) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- This is a clever disguise for an Intervals problem. The "first occurrence" to "last occurrence" of a character defines its interval.
- Expanding the 'max_end' as we traverse perfectly mirrors merging overlapping intervals on the fly.
 *
- Status: Accepted
 */