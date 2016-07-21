/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 16-06-20 03:49
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size == 0) return 0;
        if (size == 1) return A[0];
        std::sort(A.begin(), A.end());
        int i = 0;
        while (i < size-2) {
            if (A[i]==A[i+1] && A[i+1] == A[i+2]) {
                i = i + 3;
            } else {
                return A[i];
            }
        }
        return A[i];
    }
};