/*
- ============================================================
- Problem   : Design a Text Editor
- LeetCode  : https://leetcode.com/problems/design-a-text-editor/
- Problem # : 2296
- Difficulty: Hard
- Topic     : Linked List, Design, String
 *
- Approach:
- Use a C++ std::list<char> (which is a doubly linked list) and a list iterator acting as the cursor.
- std::list provides O(1) insertions and deletions at the iterator position.
- Cursor movements are just stepping the iterator forward or backward.
 *
- Time Complexity  : O(k) where k is the length of text added/deleted/returned (O(1) per character)
- Space Complexity : O(n)
- ============================================================
 */

#include <string>
#include <list>
#include <algorithm>

using namespace std;

class TextEditor {
    list<char> text;
    list<char>::iterator cursor;
    
    string getLeftText() {
        string res = "";
        auto it = cursor;
        int count = 10;
        while (it != text.begin() && count > 0) {
            it--;
            res += *it;
            count--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
public:
    TextEditor() {
        cursor = text.begin();
    }
    
    void addText(string s) {
        for (char c : s) {
            text.insert(cursor, c); // Inserts before cursor
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        while (cursor != text.begin() && k > 0) {
            cursor--; // Move left to target character
            cursor = text.erase(cursor); // Erase returns iterator to the NEXT character
            count++;
            k--;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while (cursor != text.begin() && k > 0) {
            cursor--;
            k--;
        }
        return getLeftText();
    }
    
    string cursorRight(int k) {
        while (cursor != text.end() && k > 0) {
            cursor++;
            k--;
        }
        return getLeftText();
    }
};

/*
- Key Learnings:
- std::list with an iterator is the absolute perfect C++ structure for text editors. 
- Calling text.erase(cursor) invalidates the erased iterator, but conveniently returns a valid iterator pointing to the subsequent element.
 *
- Status: Accepted
 */