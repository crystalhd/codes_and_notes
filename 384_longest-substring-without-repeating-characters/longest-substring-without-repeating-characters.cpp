/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/longest-substring-without-repeating-characters
@Language: C++
@Datetime: 16-07-19 23:15
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int size = s.size();
        if (size == 0 || size == 1) return size;
        //std::unordered_map<char, int> record;
        int i = 0;
        int max = 0;
       // std::vector<int> init(128, -1);
       // std::vector<int> record(init);
        std::unordered_map<char, int> record;
        int count = 0;
        while (i < size) {
            std::cerr<<s[i]<<" ";
            if (record.find(s[i]) == record.end()) {
                ++count; 
                record[s[i]] = i;
                ++i;
            } else {
                int prev = record[s[i]];
                max = max >= count ? max : count;
                count = 0;
                i = prev + 1;
                record.clear();
            }
        }
        return max >= count ? max : count;
    }
};