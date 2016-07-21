/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 16-07-11 18:02
*/

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    struct cmpString {
        bool operator()(const string& s1, const string& s2) {
            
            return (s1+s2) >= (s2+s1) ? true: false;
        }
    };
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> record;
        string result = "";
        int size = num.size();
        if (size == 0) return result;
        if (size == 1) {
            result += to_string(num[0]);
            return result;
        }
        int zeroCount = 0;
        for (int i = 0; i < size; ++i) {
            record.push_back(to_string(num[i]));
            if (num[i] == 0) {
                ++zeroCount;
            }
        }
        if (zeroCount == num.size()) {
            return "0";
        }
        cmpString sortString;
        std::sort(record.begin(), record.end(), sortString);
        for (int i = 0; i < record.size(); ++i) {
            result += record[i];
        }
        int i = 0;
        while (i < (result.size()-1)){
            if (result[i] == '0') {
                ++i;
            } else {
                break;
            }
        }
        
        return result.substr(i);
    }
};