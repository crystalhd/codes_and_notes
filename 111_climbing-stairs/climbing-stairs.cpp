/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 16-05-30 15:53
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n <= 1) {
            return 1;
        }
        int a = 1;
        int b = 1;
        int c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            int tmp = b;
            b = c;
            a = tmp;
        }
        return c;
    }
};
