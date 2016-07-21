/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 16-06-13 22:29
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if (n == 0) return 0;
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};
