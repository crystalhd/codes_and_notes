/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 16-06-02 22:13
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string result;
        if (strs.size() == 0) return result;
        if (strs.size() == 1) return strs[0];
        string first = strs[0];
        for (int i = 0; i < first.size(); ++i) {
            char c = first[i];
            int j = 1;
            for (j; j < strs.size(); ++j) {
                if (strs[j][i] == c) {
                    continue;
                } else {
                    return result;
                }
            }
            if (j == strs.size()) {
                result.push_back(c);
            }
        }
        return result;
    }
};