/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/en/problem/backpack/
@Language: C++
@Datetime: 16-08-09 09:22
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int size = A.size();
        if (size == 0 || m == 0) return 0;
        if (size == 1) {
            if (A[0] <= m) return A[0];
            else
                return 0;
        }
        std::vector<bool> dp(m+1, 0);
        dp[0] = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = m; j >= 0; --j) {
                if (dp[j] == 1) {
                    if (j + A[i] <= m) {
                        dp[j+A[i]] = 1;
                    }
                }
            }
        }
        for (int i = m; i >= 0; --i) {
            if (dp[i] == 1) return i;
        }
    }
};

Analyze:
maintain a 1-D array: dp[m+1]
update dp[m+1] each time iterate an element from A[],
dp[i]=1 means there are combination in A[] can generate a sum of i.
after iterate all elements from A[]
find the largest i s.t., dp[i] = 1
