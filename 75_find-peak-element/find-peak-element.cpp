/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 16-07-08 21:00
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size == 0) return -1;
        if (size == 1) return A[0];
        return recursive(A, 0, size - 1);
    }
    int recursive (vector<int> A, int begin, int end) {
        if (begin + 1 >= end) {
            return -1;
        }
        int mid = begin + (end-begin)/2;
        if (A[mid] > A[mid+1] && A[mid] > A[mid-1]) {
            return mid;
        }
        int r1 = recursive(A, begin, mid);
        if (r1 != -1) {
            return r1;
        } else {
            int r2 = recursive(A, mid, end);
            return r2;
        }
    }
};
