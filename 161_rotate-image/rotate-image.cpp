/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/rotate-image
@Language: C++
@Datetime: 16-06-07 18:43
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int rows = matrix.size();
        if (rows == 0) {
            return;
        }
        int cols = matrix[0].size();
        if (cols == 0 || cols != rows) {
            return;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int j = 0; j < cols/2; ++j) {
            for (int i = 0; i < rows; ++i) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][cols-1-j];
                matrix[i][cols-1-j] = tmp;
            }
        }
        return;
    }
};