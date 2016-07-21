/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: C++
@Datetime: 16-07-10 16:57
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n==0 || n==1) return 1;
        vector<int> result(n+1, 0);
        result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                tmp += (result[j]*result[i-1-j]);
            }
            result[i] = tmp;
        }
        return result[n];
    }
};