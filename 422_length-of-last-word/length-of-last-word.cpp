/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 16-06-13 22:14
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int size = s.size();
        for (int i = size - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                continue;
            }
            int count = 0;
            while (i >= 0 && s[i] != ' ') {
                ++count;
                --i;
            }
            return count;
        }
        return 0;
    }
};