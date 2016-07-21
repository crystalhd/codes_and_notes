/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-06-02 17:54
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (!(target && source)) return -1;
        string s(source);
        string t(target);
        if (t.size() == 0) return 0;
        if (s.size() == 0) return -1;
        if (s.size() < t.size()) {
            return -1;
        }
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            int tmp = i;
            // std::cerr<<tmp<<"\n";
            while (i < s.size() && j < t.size()) {
                if (s[i] == t[j]) {
                    ++i;
                    ++j;
                } else {
                    j = 0;
                    i = tmp + 1;
                    break;
                }
                // std::cerr<<"while: "<<i<<" "<<j<<"\n";
            }
            if (j == t.size()) {
                return tmp;
            }
        }
        return -1;
    }
};
