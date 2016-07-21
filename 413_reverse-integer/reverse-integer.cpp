/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-06-20 03:40
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        if (n == INT_MIN || n == 0) return 0;
        int sign = n >= 0 ? 1 : -1;
        n = n >= 0 ? n : -n;
        std::vector<int> digit;
        while (n != 0) {
            digit.push_back(n % 10);
            n = n / 10;
        }
        long result = 0;
       // std::reverse(digit.begin(), digit.end());
        for (int i = 0; i < digit.size(); ++i) {
            result = result * 10 + digit[i];
        }
        if (result * sign > INT_MAX || result * sign < INT_MIN) return 0;
        return result * sign;
    }
};