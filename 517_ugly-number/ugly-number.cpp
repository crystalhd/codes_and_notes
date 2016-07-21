/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-07-18 17:34
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        // Write your code here
        while (num%2 == 0) {
            num = num / 2;
        }
        if (num == 1) return true;
        while (num % 3 == 0) {
            num = num / 3;
        }
        if (num == 1) return true;
        while (num % 5 == 0) {
            num = num / 5;
        }
        if (num ==1) return true;
        return false;
    }
};