/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 16-07-10 16:22
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            vector<int> tmp (n, 1);
            result.push_back(tmp);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                result[i][j] = result[i-1][j] + result[i][j-1];
            }
        }
        return result[m-1][n-1];
    }
};
