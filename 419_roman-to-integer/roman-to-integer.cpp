/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/roman-to-integer
@Language: C++
@Datetime: 16-07-18 21:11
*/

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        int size = s.size();
        if (size==0) return 0;
        std::unordered_map<char, int> record;
        record['I'] = 1;
        record['V'] = 5;
        record['X'] = 10;
        record['L'] = 50;
        record['C'] = 100;
        record['D'] = 500;
        record['M'] = 1000;
        int result = 0;
        int i = 0;
        for (; i < size-1; ++i) {
            if (record[s[i]] >= record[s[i+1]]) {
                result += record[s[i]];
            } else {
                result += (record[s[i+1]] - record[s[i]]);
                ++i;
            }
        }
        if (i==size-1) {
            result += record[s[i]];
        }
        return result;
    }
};