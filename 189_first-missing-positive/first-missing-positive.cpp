/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 16-06-03 03:37
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if (A.size() == 0) return 1;
        int i = 0;
        while(i < A.size()) {
            if (A[i] != i+1 && A[i] > 0 && A[i] <= A.size() && A[i] != A[A[i]-1]) {
                int tmp = A[i];
                A[i] = A[tmp-1];
                A[tmp-1] = tmp;
            } else {
                ++i;
            }
        }
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i + 1) {
                return i+1;
            }
        }   
        return A.size() + 1;
        
    }
};