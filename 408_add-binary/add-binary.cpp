/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-06-02 18:15
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string result;
        int lengthA = a.size();
        int lengthB = b.size();
        if (lengthA == 0) return b;
        if (lengthB == 0) return a;
        int i = lengthA - 1;
        int j = lengthB - 1;
        int extra = 0;
        while (i >= 0 || j >= 0) {
            int num1 = i >= 0 ? (a[i] - '0') : 0;
            int num2 = j >= 0 ? (b[j] - '0') : 0;
            // std::cerr<<"num1, num2: "<<num1<<" "<<num2<<"\n";
            int tmp = (num1 + num2 + extra) % 2;
            extra = (num1 + num2 + extra) / 2;
            // std::cerr<<"tmp. extra: "<<tmp<<" "<<extra<<"\n";
            result += to_string(tmp);
            --i;
            --j;
        }
        if (extra == 1) {
            // std::cerr<<"have extra bit.\n";
            result += "1";
        }
        std::cerr<<result<<"\n";
        std::reverse(result.begin(), result.end());
        return result;
    }
};