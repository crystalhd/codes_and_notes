/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-07-08 17:50
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int size = A.size();
        if (size == 0) return false;
        if (size == 1 && A[0] != target) return false;
        int begin = 0;
        int end = size - 1;
        while (begin < end) {
            while (A[begin] > target) {
                ++begin;
            }
            while (A[end] < target) {
                --end;
            }
            while (begin < end) {
                int mid = begin + (end-begin)/2;
                if (A[mid] == target) {
                    return true;
                }
                if (A[mid] < target) {
                    begin = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
        if (A[begin] == target) return true;
        else return false;
    }
};