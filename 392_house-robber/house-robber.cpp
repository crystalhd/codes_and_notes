/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: C++
@Datetime: 16-05-30 16:31
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size == 0) return 0;
        if (size == 1) return A[0];
        long long a = 0;
        long long b = A[0];
        long long c = 0;
        for (int i = 2; i <= size; ++i) {
            c = max(a + A[i-1], b);
            long long tmp = b;
            b = c;
            a = tmp;
        }
        return c;
    }
};