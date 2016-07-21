/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 16-07-10 04:31
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int size = A.size();
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if (size == 0 || (size == 1 && A[0] != target)) return result;
        if (size == 1 && A[0] == target) {
            result[0] = 0;
            result[1] = 0;
            return result;
        }
        int begin = 0;
        int end = A.size() - 1;
        result[0] = searchLower(A, begin, end, target);
        result[1] = searchUpper(A, begin, end, target);
        return result;
    }
    int searchLower (vector<int>& A, int begin, int end, int target) {
        if (begin > end) return -1;
        if (begin == end && A[begin] == target) {
            return begin;
        }
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (begin>=0 && begin < A.size() && A[begin] == target) {
            return begin;
        }
        return -1;
    }
    int searchUpper(vector<int>& A, int begin, int end, int target) {
        if (begin > end) return -1;
        if (begin == end && A[end] == target) {
            return end;
        }
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                begin = mid + 1;
            } else {
                begin = mid + 1;
            }
        }
        if (end >= 0 && end < A.size() && A[end] == target) {
            return end;
        }
        return -1;
    }
};