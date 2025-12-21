/*
- ============================================================
- Problem   : Exclusive Time of Functions
- LeetCode  : https://leetcode.com/problems/exclusive-time-of-functions/
- Problem # : 636
- Difficulty: Medium
- Topic     : Array, Stack
 *
- Approach:
- Parse the logs. Use a stack to hold the function IDs.
- On 'start': add time difference to the current top function on the stack, then push the new function.
- On 'end': pop the function, add its interval, and advance the 'prev_time' by 1 to represent the end of the second.
 *
- Time Complexity  : O(n)
- Space Complexity : O(n)
- ============================================================
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    struct Log {
        int id;
        bool is_start;
        int time;
    };
    
    Log parseLog(string& log) {
        int pos1 = log.find(':');
        int pos2 = log.find_last_of(':');
        return {
            stoi(log.substr(0, pos1)),
            log.substr(pos1 + 1, pos2 - pos1 - 1) == "start",
            stoi(log.substr(pos2 + 1))
        };
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prev_time = 0;
        
        for (string& log_str : logs) {
            Log log = parseLog(log_str);
            
            if (log.is_start) {
                if (!st.empty()) {
                    res[st.top()] += log.time - prev_time;
                }
                st.push(log.id);
                prev_time = log.time;
            } else {
                res[st.top()] += log.time - prev_time + 1;
                st.pop();
                prev_time = log.time + 1;
            }
        }
        
        return res;
    }
};

/*
- Key Learnings:
- Intervals don't always come as [start, end] pairs; sometimes they come as a chronological stream of events.
- A Stack is the perfect structure to handle nested/overlapping intervals that "pause" and "resume".
 *
- Status: Accepted
 */