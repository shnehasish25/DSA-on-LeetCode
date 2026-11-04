/*
- ============================================================
- Problem   : Car Fleet II
- LeetCode  : https://leetcode.com/problems/car-fleet-ii/
- Problem # : 1776
- Difficulty: Hard
- Topic     : Array, Stack, Monotonic Stack, Math
 *
- Approach:
- Iterate right to left. Use a stack to keep track of the cars that could potentially bottleneck the current car.
- A car only cares about colliding with the cars ahead of it. If a car ahead is faster, it will never collide, so pop it.
- If a car ahead collides with *its* next car BEFORE the current car hits it, it merges. We must check collision time against the fleet ahead.
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
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1.0);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            int p1 = cars[i][0], s1 = cars[i][1];
            
            while (!st.empty()) {
                int j = st.top();
                int p2 = cars[j][0], s2 = cars[j][1];
                
                if (s1 <= s2) {
                    st.pop(); // Cannot catch a faster/equal car
                    continue;
                }
                
                double collide_time = (double)(p2 - p1) / (s1 - s2);
                
                if (res[j] == -1.0 || collide_time <= res[j]) {
                    res[i] = collide_time;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};

/*
- Key Learnings:
- The condition (collide_time <= res[j]) is pure genius. If we hit the car *after* it has already merged into a slower fleet, we shouldn't calculate our math against its original speed.
- Pop it, because we will just collide with the slower fleet leader instead.
 *
- Status: Accepted
 */