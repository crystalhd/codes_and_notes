/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-06-08 18:30
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count = 0;
        int shift = 32;
        int x = a ^ b;
        while (shift > 0) {
            if (x & 1) {
                ++count;
            }
            x >>= 1;
            --shift;
        }
        return count;
    }
};