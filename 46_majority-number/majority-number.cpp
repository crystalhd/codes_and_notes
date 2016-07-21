/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-06-01 23:52
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        /* 
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        return nums[size/2];
        */
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int candidate = nums[0];
        int count = 1;
        for (int j = 1; j < size; ++j) {
            if (nums[j] == candidate) {
                ++count;
            } else {
                if (count == 0) {
                    candidate = nums[j];
                    count = 1;
                } else {
                    --count;
                }
            }
        }
        return candidate;
    }
};
