/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-06-03 16:27
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        std::vector<long long> result;
        if (nums.size() == 0) return result;
        int head;
        int end;
        for (int i = 0; i < nums.size(); ++i) {
            head = 0;
            end = nums.size() - 1;
            long long tmp = 1;
            while (head < i) {
                tmp *= nums[head];
                ++head;
            }
            while (end > i) {
                tmp *= nums[end];
                --end;
            }
            result.push_back(tmp);
        }
        return result;
    }
};