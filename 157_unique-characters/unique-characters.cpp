/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 16-06-10 19:30
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        std::sort(str.begin(), str.end());
        int size = str.size();
        if (size == 0 || size == 1) return true;
        for (int i = 0; i < size-1; ++i) {
            if (str[i] == str[i+1]) {
                return false;
            }
        }
    }
};