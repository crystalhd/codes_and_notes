/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 16-06-19 22:00
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int height = grid.size();
        if (height == 0) return 0;
        int width = grid[0].size();
        if (width == 0) return 0;
        int result[height][width];
        result[0][0] = grid[0][0];
        for (int i = 1; i < width; ++i) {
            result[0][i] = result[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < height; ++i) {
            result[i][0] = result[i-1][0] + grid[i][0]; 
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
                // std::cerr<<"min: "<<min(result[i-1][j], result[i][j-1])<<" ";
                // std::cerr<<"grid: "<<grid[i-1][j-1];
            }
        }
        return result[height-1][width-1];
    }
};
