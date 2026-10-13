/*
- ============================================================
- Problem   : Asteroid Collision
- LeetCode  : https://leetcode.com/problems/asteroid-collision/
- Problem # : 735
- Difficulty: Medium
- Topic     : Array, Stack, Simulation
 *
- Approach:
- Asteroids only collide if a right-moving one (+) is to the left of a left-moving one (-).
- Push '+' to stack. If '-', check the top of the stack.
- Resolve collisions recursively using a while loop until the stack is empty, the top is '-', or both explode.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && ast < 0 && st.back() > 0) {
                if (st.back() < -ast) {
                    st.pop_back(); // Stack asteroid explodes, current asteroid keeps going
                    continue;
                } else if (st.back() == -ast) {
                    st.pop_back(); // Both explode
                }
                destroyed = true; // Current asteroid explodes (or both)
                break;
            }
            
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};

/*
- Key Learnings:
- The 'continue' statement within the while loop perfectly chains cascading explosions for massive negative asteroids tearing through a stack of positive ones.
- Using a boolean flag cleanly separates the collision logic from the push logic.
 *
- Status: Accepted
 */