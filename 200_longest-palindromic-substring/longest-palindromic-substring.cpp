/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/longest-palindromic-substring
@Language: C++
@Datetime: 16-07-19 23:25
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        if (size == 0 || size == 1) return s;
        string result = s.substr(0,1);
       // int index = 1;
        for (int i = 0; i<s.size()-1; ++i) {
            int first = i;
            int second = i;
            while (first>=0 && s[first] == s[i]) {
                --first;
            }
            while (second<size && s[second] == s[i]) {
                ++second;
            }
            while(first>=0 && second < size && s[first]==s[second]) {
                --first;
                ++second;
            }
            std::cerr<<first<<" "<<second<<" ";
            if (second-first-1 > result.size()) {
                result = s.substr(first+1, second-first-1);
            }
            std::cerr<<result<<";";
        }
        return result;
    }
};