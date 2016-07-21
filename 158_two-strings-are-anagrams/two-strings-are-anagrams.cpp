/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-06-03 00:20
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) return false;
        std::vector<char> record(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++record[s[i]];
        }
        for (int i = 0; i < t.size(); ++i) {
            --record[t[i]];
            if (record[t[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};