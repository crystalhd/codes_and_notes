/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 16-06-19 22:26
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int row = triangle.size();
        if (row == 0) return 0;
        if (row == 1) return triangle[0][0];
        vector<int> result(row, 0);
        result[0] = triangle[0][0];
        for (int i = 1; i < row; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i) {
                    result[j] = result[j-1] + triangle[i][j];
                } else if (j == 0) {
                    result[j] = result[j] + triangle[i][j];
                } else {
                    result[j] = min(result[j-1], result[j]) + triangle[i][j];
                }
            }
        }
        return *std::min_element(result.begin(), result.end());
    }
};
