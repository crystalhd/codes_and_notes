/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-06-05 00:20
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return 0;
        int begin = 0;
        int end = A.size() - 1;
        if (target > A[end]) return end + 1;
        if (target < A[begin]) return 0;
        while (begin < end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] == target) {
                return mid;
            }
            if (mid == begin) {
                return begin + 1;
            }
            if (A[mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
    }
};