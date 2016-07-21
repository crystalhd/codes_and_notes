/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-07-10 05:29
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int row = matrix.size();
        if (row == 0) return false;
        int col = matrix[0].size();
        if (col == 0) return false;
        if (target < matrix[0][0] || target > matrix[row-1][col-1]) {
            return false;
        }
        int begin = 0;
        int end = row - 1;
        int mid;
        while (begin <= end) {
            mid = begin + (end-begin)/2;
            if (mid == row - 1) break;
            if (matrix[mid][0] > target && matrix[mid+1][0] > target) {
                end = mid;
            } else if (matrix[mid][0] < target && matrix[mid+1][0] < target) {
                begin = mid + 1;
            } else {
                break;
            }
        }
        int small = 0;
        int large = col-1;
        while (small <= large) {
            int tmp = small + (large-small)/2;
            if (matrix[mid][tmp] < target) {
                small = tmp + 1;
            } else if (matrix[mid][tmp] > target) {
                large = tmp - 1;
            } else 
            {
                return true;
            }
        }
        return false;
    }
};
