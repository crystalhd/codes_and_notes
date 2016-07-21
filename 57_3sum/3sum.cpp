/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 16-06-03 03:01
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int curTarget = 0 - nums[i];
            while(left < right) {
                int curSum = nums[left] + nums[right];
                if (curSum == curTarget) {
                    std::vector<int> sol;
                    sol.push_back(nums[i]);
                    sol.push_back(nums[left]);
                    sol.push_back(nums[right]);
                    result.push_back(sol);
                    ++left;
                    --right;
                    while (nums[left] == nums[left-1]) {
                        ++left;
                    }
                    while (nums[right] == nums[right+1]) {
                        --right;
                    }
                }
                else if (curSum < curTarget) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return result;
    }
};
