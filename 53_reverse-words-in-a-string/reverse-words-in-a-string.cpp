/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-05-29 17:43
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        unsigned int size = s.size();
        if (size == 0 || size == 1) {
            return s;
        }
        string result ;
        int i = size - 1;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
            {
                --i;
            }
            if (i < 0)
            {
                break;
            }
            string tmp;
            for (; i >= 0 && s[i] != ' '; --i)
            {
                tmp.push_back(s[i]);
                
            }
            if (result.size() > 0)
            {
                result.append(" ");
            }
            std::reverse(tmp.begin(), tmp.end());
            result.append(tmp);
        }
      
        return result;
    }
};