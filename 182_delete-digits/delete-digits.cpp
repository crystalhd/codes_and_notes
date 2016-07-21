/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 16-07-15 23:08
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int n = A.size();
        string result = "";
        if (n == k) {
            return result;
        }
        std::stack<char> record;
        for (int i = 0; i < n; ++i) {
            if (record.size() == 0) {
                record.push(A[i]);
                continue;
            }
            int top = record.top()-'0';
            int cur = A[i] - '0';
            if (record.size() >= n-k && cur >= top) {
                continue;
            }
            while (top > cur && (n - i + record.size() - 1) >= (n-k)) {
                record.pop();
                if (record.empty()) {
                    break;
                }
                top = record.top()-'0';
            }
            record.push(A[i]);
        }
        while (!record.empty()) {
            result += record.top();
            record.pop();
        }
        std::reverse(result.begin(), result.end());
        int i = 0;
        while (i<result.size() && result[i]=='0') {
            ++i;
        }
        result = result.substr(i);
        return result;
    }
};
