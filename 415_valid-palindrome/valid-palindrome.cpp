/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 16-06-27 06:54
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0 || size == 1) {
            return true;
        }
        int begin = 0;
        int end = size - 1;
        while (begin < end && begin < size && end >= 0) {
            if (!isAlphabetNum(s[begin])) {
                ++begin;
            }
            else if (!isAlphabetNum(s[end])) {
                --end;
            } else {
                int tmp1 = charToNum(s[begin]);
                int tmp2 = charToNum(s[end]);
                std::cerr<<tmp1<<" "<<tmp2<<"\n";
                if (tmp1 != tmp2) {
                    return false;
                }
                ++begin;
                --end;
            }
        }
        return true;
    }
    bool isAlphabetNum(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }
    int charToNum(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        }
        if (c >= 'A' && c <= 'Z') {
            return c - 'A';
        }
        if (c >= '0' && c <= '9') {
            return c - '0';
        }
    }
  
};