/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/divide-two-integers
@Language: C++
@Datetime: 16-06-02 20:30
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        bool sign = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = false;
        }
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
       
        unsigned long d1 = (long)dividend > 0 ? (long)dividend : -(long)dividend;
        unsigned long d2 = (long)divisor > 0 ? (long)divisor : -(long)divisor;
        int count = 0;
        while (d1 >= d2) {
            int i = 0;
            while ((d2<<i) <= d1) {
                ++i;
            }
            count += (1 << (i-1));
            d1 -= (d2<<(i-1));
        }
        return sign == true ? count : -count;
        
    }
};