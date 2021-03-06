/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-06-03 01:48
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        for (; i >= 0 && j >= 0; --k) {
            if (A[i] >= B[j]) {
                A[k] = A[i];
                --i;
            } else {
                A[k] = B[j];
                --j;
            }
        }
        while (j >= 0) {
            A[k] = B[j];
            --k;
            --j;
        }
        return;
    }
};