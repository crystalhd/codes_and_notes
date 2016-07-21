/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 16-06-05 00:00
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x <= 0) return 0;
        if (x == 1) return 1;
        int begin = 0;
        int end = x;
        while (begin+1 < end) {
            long mid = (begin+end)/2;
            long result = mid * mid;
            if (result > x) {
                end = mid;
            } else if (result < x) {
                begin = mid;
            } else {
                return mid;
            }
        }
        return begin;
    }
};