/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/set-matrix-zeroes
@Language: C++
@Datetime: 16-06-08 19:19
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        /* 
        // use space O(m+n);
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        if (cols == 0) return;
        std::set<int> rowRecord;
        std::set<int> colRecord;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    rowRecord.insert(i);
                    colRecord.insert(j);
                }
            }
        }
        for (auto it = rowRecord.begin(); it != rowRecord.end(); ++it) {
            int index = *it;
            for (int j = 0; j < cols; ++j) {
                matrix[index][j] = 0;
            }
        }
        for (auto it = colRecord.begin(); it != colRecord.end(); ++it) {
            int index = *it;
            for (int i = 0; i < rows; ++i) {
                matrix[i][index] = 0;
            }
        }
        return;
        */
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        if (cols == 0) return;
        bool firstCol = false;
        bool firstRow = false;
        for (int i = 0; i < rows; ++i) {
            if (!firstCol && matrix[i][0] == 0) {
                firstCol = true;  // need to be set whole col as zero
            }
        }
        for (int i = 0; i < cols; ++i){
            if (!firstRow && matrix[0][i] == 0) {
                firstRow = true;
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstCol == true) {
            for (int i = 0; i <rows; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (firstRow == true) {
            for (int j = 0; j < cols; ++j) {
                matrix[0][j] = 0;
            }
        }
        return;
    }
};