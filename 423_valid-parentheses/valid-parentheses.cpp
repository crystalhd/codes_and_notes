/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: C++
@Datetime: 16-06-27 06:28
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0) {
            return true;
        }
        if (size == 1) {
            return false;
        }
        std::stack<char> record;
        for (int i = 0; i < size; ++i) {
            if (record.size() == 0) {
                record.push(s[i]);
                continue;
            }
            if (isPair(record.top(), s[i])) {
                record.pop();
            } else {
                record.push(s[i]);
            }
        }
        return record.empty();
        
    }
    bool isPair(char c1, char c2) {
        if (c1 == '(') {
            return c2 == ')';
        } else if (c1 == '{') {
            return c2 == '}';
        } else if (c1 == '[') {
            return c2 == ']';
        } else {
            return false;
        }
        
    }
};