/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/en/problem/backpack/
@Language: C++
@Datetime: 16-08-09 09:22
*/

// backpack I 
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
/* *********************************************************************
Analyze:
maintain a 1-D array: dp[m+1]
update dp[m+1] each time iterate an element from A[],
dp[i]=1 means there are combination in A[] can generate a sum of i.
after iterate all elements from A[]
find the largest i s.t., dp[i] = 1
************************************************************************/

// backpack II
// samiliar as backpack I. Difference, instead of boolean whether exist size i or not, 
// dp[i] stores store exit size i, and the value at size i. initialize as -1. dp[0] = 0;
// find the max element in dp[i]
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int size = A.size();
        if (size == 0 || m == 0) {
            return 0;
        }
        if (size == 1) {
            if (A[0] <= m) {
                return V[0];
            } else {
                return 0;
            }
        }
        std::vector<int> dp(m+1, -1);
        dp[0] = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = m; j >= 0; --j) {
                if (dp[j] != -1) {
                    if (j + A[i] > m) continue;
                    dp[j+A[i]] = max(dp[j+A[i]], dp[j] + V[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
