/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-06-03 00:19
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (B.size() == 0) return true;
        if (B.size() > A.size()) return false;
        std::vector<int> record(26, 0);
        std::cerr<<record.size()<<"\n";
        for (int i = 0; i < A.size(); ++i) {
            std::cerr<<A[i] - 'A'<<" ";
            ++record[A[i]-'A'];
        }
        std::cerr<<"\n";
        // std::cerr<<"record size: "<<record.size()<<"\n";
        for (int i = 0; i < B.size(); ++i) {
            int num = B[i] - 'A';
            --record[num];
            if (record[num] < 0) {
                return false;
            }
        }
        return true;
    }
};
