/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: C++
@Datetime: 16-07-11 02:56
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n<=0) return false;
        bool result = (n & (n-1));
        std::cerr<<result;
        return result==0;
    }
};