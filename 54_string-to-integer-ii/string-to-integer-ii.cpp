/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 16-06-04 22:45
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if (str.size() == 0) return 0;
        int i = 0;
        int sign = 1;
        while (str[i] == ' ') {
            ++i;
        }
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        if (str[i] == '+') {
            ++i;
        }
        while (str[i] == '0') {
            ++i;
        }
        long result = 0;
        for (i; i < str.size(); ++i) {
            if (str[i] == '.') {
                break;
            }
            int num = str[i] - '0';
            if (num < 0 || num > 9) {
                break;
            }
            result = result * 10 + num;
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } 
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }
        return static_cast<int>(result*sign);
        
    }
};