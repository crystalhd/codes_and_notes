/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 16-07-11 04:23
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long  fac = 5;
        long long result = 0;
        if (n < 5) {return 0;}
        while (n>=fac) {
            result += (n/fac);
            fac = fac * 5;
        }
        return result;
    }
};
