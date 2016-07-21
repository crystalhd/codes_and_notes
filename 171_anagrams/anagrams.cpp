/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-06-02 22:45
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0 || strs.size() == 1) return strs;
        std::unordered_map<string, vector<string>> record;
        for (int i = 0; i < strs.size(); ++i) {
            string cur = strs[i];
            std::sort(cur.begin(), cur.end());
            if (record.find(cur) == record.end()) {
                std::vector<string> strList;
                strList.push_back(strs[i]);
                record[cur] = strList;
            } else {
                record[cur].push_back(strs[i]);
            }
        }
        vector<string> result;
        for (auto it = record.begin(); it != record.end(); ++it) {
            std::vector<string> curList = it->second;
            if (curList.size() > 1) {
                for (int j = 0; j < curList.size(); ++j) {
                    result.push_back(curList[j]);
                }
            }
        }
        return result;
    }
};
