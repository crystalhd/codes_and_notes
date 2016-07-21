/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 16-06-08 18:42
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int numSpace = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                ++numSpace;
            }
        }
        int newLength = length + numSpace * 2;
        int j = length - 1;
        int i = newLength - 1;
        while (i >= 0 && j >= 0) {
            if (string[j] != ' ') {
                string[i] = string[j];
                --j;
                --i;
                continue;
            }
            string[i] = '0';
            string[i-1] = '2';
            string[i-2] = '%';
            i = i - 3;
            --j;
        }
        return newLength;
    }
}; 