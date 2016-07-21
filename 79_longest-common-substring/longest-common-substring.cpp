/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-06-03 01:13
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if (A.size() == 0 || B.size() == 0) return 0;
       // int* D[] = new int [A.size()+1][B.size()+1];
        vector<vector<int>> D(A.size()+1, vector<int>(B.size()+1, 0));
        int longest = 0;
        for (int i = 0; i <= A.size(); ++i) {
            for (int j = 0; j <= B.size(); ++j) {
                if (i == 0 || j == 0) {
                    D[i][j] = 0;
                } else {
                    if (A[i-1] == B[j-1]) {
                        D[i][j] = D[i-1][j-1] + 1;
                    } else {
                        D[i][j] == 0;
                    }
                }
                longest = longest >= D[i][j] ? longest : D[i][j];
            }
        }
        return longest;
    }
};
