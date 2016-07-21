/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 16-07-11 05:53
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (a == 0) return 0;
        long result = power(a, b, n);
        return (int)result;
        
    }
    long power(int a, int b, int n) {
        if (n == 0) return 1 % b;
        if (n == 1) return a % b;
        long long r1 = power(a, b, n/2);
        r1 = ((r1%b) * (r1%b))%b;
        if (n % 2 == 1) {
            r1 *= power(a, b, 1);
            
        }
        r1 %= b;
        return r1;
    }
};