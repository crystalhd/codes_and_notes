/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-06-02 19:36
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        /*
        std::vector<int> result;
        if (digits.size() == 0) return result;
        int size = digits.size();
        int extra = 0;
        for (int i = size-1; i >= 0; --i) {
            int num = digits[i];
            if (i == size-1) ++num;
            result.push_back((num + extra) % 10);
            extra = (num + extra) / 10;
        }
        if (extra == 1) {
            result.push_back(extra);
        }
        std::reverse(result.begin(), result.end());
        return result;
        */
        if (digits.size() == 0) return digits;
        std::vector<int> result (digits.size(), 0);
        int size = digits.size();
        int carry = 1;
        for (int i = size - 1; i >= 0; --i) {
            int num = (digits[i] + carry) % 10;
            result[i] = num;
            carry = (digits[i] + carry) / 10;
        }
        if (carry == 1)
        {
            result.insert(result.begin(), carry);
        }
        return result;
    }
};