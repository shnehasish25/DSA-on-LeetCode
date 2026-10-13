/*
- ============================================================
- Problem   : Baseball Game
- LeetCode  : https://leetcode.com/problems/baseball-game/
- Problem # : 682
- Difficulty: Easy
- Topic     : Array, Stack, Simulation
 *
- Approach:
- Use a vector as a stack to keep track of valid scores.
- On '+': Push the sum of the top two scores. On 'D': Push double the top score. On 'C': Pop the top score.
- Return the sum of all elements in the vector at the end.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;
        
        for (const string& op : operations) {
            if (op == "+") {
                st.push_back(st[st.size() - 1] + st[st.size() - 2]);
            } else if (op == "D") {
                st.push_back(st.back() * 2);
            } else if (op == "C") {
                st.pop_back();
            } else {
                st.push_back(stoi(op));
            }
        }
        
        int sum = 0;
        for (int score : st) sum += score;
        return sum;
    }
};

/*
- Key Learnings:
- Since the '+' operation requires access to the top TWO elements, using std::vector is slightly cleaner than std::stack as we don't have to pop/re-push the top element to peek beneath it.
- stoi() perfectly handles negative string conversions.
 *
- Status: Accepted
 */