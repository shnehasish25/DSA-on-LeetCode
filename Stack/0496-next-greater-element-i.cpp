/*
- ============================================================
- Problem   : Next Greater Element I
- LeetCode  : https://leetcode.com/problems/next-greater-element-i/
- Problem # : 496
- Difficulty: Easy
- Topic     : Array, Hash Table, Stack, Monotonic Stack
 *
- Approach:
- Find the Next Greater Element for ALL elements in nums2 using a Monotonic Stack, and map the results in a Hash Map (value -> next_greater).
- Iterate through nums1 and look up the answers in the Hash Map in O(1) time.
 *
- Time Complexity  : O(n + m)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge_map;
        stack<int> st;
        
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nge_map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        vector<int> res;
        for (int num : nums1) {
            if (nge_map.count(num)) {
                res.push_back(nge_map[num]);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The Monotonic Stack finds the "next greater" relationship natively. 
- Using a Hash Map bridges the gap between processing the superset (nums2) and answering queries for the subset (nums1).
 *
- Status: Accepted
 */