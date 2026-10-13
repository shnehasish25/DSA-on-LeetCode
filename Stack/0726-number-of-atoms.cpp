/*
- ============================================================
- Problem   : Number of Atoms
- LeetCode  : https://leetcode.com/problems/number-of-atoms/
- Problem # : 726
- Difficulty: Hard
- Topic     : Hash Table, String, Stack
 *
- Approach:
- Use a stack of Hash Maps. The stack holds the counts of atoms for the current parenthesis scope.
- On '(', push a new empty map to the stack.
- On ')', parse the multiplier that follows it. Pop the top map, multiply all its counts, and add them to the new top map.
- Finally, extract the counts from the last remaining map and format the string.
 *
- Time Complexity  : O(n^2) worst case due to string formatting/sorting, O(n) parsing
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});
        
        int i = 0, n = formula.length();
        
        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                map<string, int> top = st.top();
                st.pop();
                i++;
                
                int multiplier = 0;
                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + (formula[i] - '0');
                    i++;
                }
                if (multiplier == 0) multiplier = 1;
                
                for (auto& p : top) {
                    st.top()[p.first] += p.second * multiplier;
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string element = formula.substr(start, i - start);
                
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                
                st.top()[element] += count;
            }
        }
        
        string res = "";
        for (auto& p : st.top()) {
            res += p.first;
            if (p.second > 1) res += to_string(p.second);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Complex nested parsing requires stacking ENTIRE environments (like hash maps), not just single characters.
- std::map automatically sorts keys alphabetically, which perfectly satisfies the output requirement without a separate sorting step.
 *
- Status: Accepted
 */