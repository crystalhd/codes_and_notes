/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 16-06-08 16:42
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        /*
        if (a == 0 || b == 0) {
            return 0;
        }
        int carry = 0;
        int result = 0;
        int shift = 0;
        while (shift < 32) {
            int tmp = (a & 1) + (b & 1) + carry;
            result += (tmp % 2) << shift;
            carry = tmp / 2;
            ++shift;
            a >>= 1;
            b >>= 1;
        }
        
        return result;*/
        
        if (b == 0) return a;
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};