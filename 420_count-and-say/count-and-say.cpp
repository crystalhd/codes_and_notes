/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 16-05-30 17:19
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if (n == 1) return "1";
        if (n == 2) return "11";
        string result = "11";
        int index = 3;
        while (index <= n) {
            string tmp;
            int j = 0;
            while (j < result.size()) {
                char c = result[j];
                int count = 0;
                while (result[j] == c) {
                    ++count;
                    ++j;
                    if (j == result.size()) {
                        break;
                    }
                }
                tmp += to_string(count);
                tmp += to_string(c - '0');
            }
            result = tmp;
            ++index;
        }
        return result;
    }
};