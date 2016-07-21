/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-07-20 02:29
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n==0) return 1.0;
        if (n==1) return x;
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        bool even = false;
        if (n%2 == 0) {
            even = true;
        } else {
            --n;
        }
        double result = 1.0;
        while (n > 1) {
            result = result * (x * x);
            n = n/2;
        }
        return even == true ? result : (result * x);
    }
};