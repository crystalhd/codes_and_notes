/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 16-06-20 03:45
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size == 0) return 0;
        if (size == 1) {
            return A[0];
        }
        std::sort(A.begin(), A.end());
        int i = 0;
        while (i < size-1) {
            if (A[i] == A[i+1]) {
                i = i+2;
            } else {
                return A[i];
            }
        }
        return A[size-1];
    }
};
