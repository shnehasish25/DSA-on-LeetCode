/*
- ============================================================
- Problem   : Fruit Into Baskets
- LeetCode  : https://leetcode.com/problems/fruit-into-baskets/
- Problem # : 904
- Difficulty: Medium
- Topic     : Array, Hash Table, Sliding Window
 *
- Approach:
- Find the longest contiguous subarray that contains at most 2 distinct numbers.
- Use an unordered_map to track the frequencies of fruits in the current window, shrinking from the left when map size > 2.
 *
- Time Complexity  : O(n)
- Space Complexity : O(1) (Hash map never exceeds size 3)
- ============================================================
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, max_fruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            max_fruits = max(max_fruits, right - left + 1);
        }
        
        return max_fruits;
    }
};

/*
- Key Learnings:
- This is a disguised version of "Longest Substring with At Most K Distinct Characters" (where K=2).
- You must completely erase a key from the map when its count reaches 0 for basket.size() to work properly.
 *
- Status: Accepted
 */