/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-06-02 04:18
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        if (A.size() == 0) {
            return 0;
        }
        int i = 0;
        int end = A.size() - 1;
        for (i; i < A.size(); ++i) {
            if (A[i] != elem) {
                continue;
            }
            while (end >= i && A[end] == elem) {
                --end;
            }
            if (end < i) {
                break;
            }
            A[i] = A[end];
            A[end] = elem;
            --end;
        }
        return i;
    }
};