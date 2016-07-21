/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/median-of-two-sorted-arrays
@Language: C++
@Datetime: 16-07-18 23:03
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        std::vector<int> sum;
        for (int i = 0; i< A.size(); ++i) {
            sum.push_back(A[i]);
        }
        for (int i = 0; i < B.size(); ++i) {
            sum.push_back(B[i]);
        }
        int size = sum.size();
        if (size == 0) return 0;
        if (size == 1) return sum[0];
        std::sort(sum.begin(), sum.end());
        int fast = 0;
        int slow = 0;
        while (fast < size-1) {
            fast += 2;
            slow += 1;
        }
        
        if (size % 2 == 0) {
            return (double)(sum[slow]+sum[slow-1])/2;
        } else {
            return sum[slow];
        }
    }
};
