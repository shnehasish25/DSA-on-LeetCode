/*
- ============================================================
- Problem   : Final Prices With a Special Discount in a Shop
- LeetCode  : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
- Problem # : 1475
- Difficulty: Easy
- Topic     : Array, Stack, Monotonic Stack
 *
- Approach:
- We need the "Next Smaller or Equal Element". Use a Monotonic Increasing Stack.
- As we iterate, if the current price is <= the price at the top of the stack, apply the discount to the top element and pop it.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = prices;
        stack<int> st; // Stores indices
        
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                res[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Naming convention: The problem is fundamentally asking for the "Next Smaller or Equal Element". 
- Initialize the result array with the base prices so any items that don't receive a discount default correctly.
 *
- Status: Accepted
 */