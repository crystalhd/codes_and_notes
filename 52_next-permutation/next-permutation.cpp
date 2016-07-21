/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/next-permutation
@Language: C++
@Datetime: 16-07-15 21:59
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size == 0 || size == 1) return nums;
        vector<int> result;
        int i = size - 1;
        for (; i >= 1 ; --i) {
            if (nums[i] <= nums[i-1]) {
                continue;
            } else {
                break;
            }
        }
        std::cerr<<"i: "<<i<<" ";
        if (i == 0) {
            for (int j = size - 1; j >= 0; --j){
                result.push_back(nums[j]);
            }
            return result;
        }
          
        for (int j = 0; j < (i-1); ++j) {
            result.push_back(nums[j]);
        }
        
        int j = size - 1;
        for (; j>=0; --j) {
            if (nums[j] <= nums[i-1]) {
                continue;
            } else {
                break;
            }
        }
        std::cerr<<"j: "<<j<<" ";
        result.push_back(nums[j]);
        nums[j] = nums[i-1];
        for (int m = size - 1; m >= i && m>=0; --m) {
            result.push_back(nums[m]);
        }
        return result;
    }
};