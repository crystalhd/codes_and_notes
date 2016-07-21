/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/4sum
@Language: C++
@Datetime: 16-06-04 23:38
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        std::vector<std::vector<int>> result;
        if (nums.size() < 4) return result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; ++i) {
           while (i>0 && nums[i] == nums[i-1]) {++i; }
           for (int j = i+1; j < nums.size()-2; ++j) {
               while(j>i+1 && nums[j] == nums[j-1]) {++j; }
            int begin = j+1;
            int end = nums.size() - 1;
            while (begin < nums.size() && end < nums.size() && begin < end) {
                int curSum = nums[i] + nums[j] + nums[begin] + nums[end];
                if (curSum == target) {
                    std::vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[begin]);
                    tmp.push_back(nums[end]);
                    result.push_back(tmp);
                    ++begin; 
                    --end;
                    while (nums[begin] == nums[begin-1]) {
                        ++begin;
                    }
                    while (nums[end] == nums[end+1]) {
                        --end;
                    }
                    
                } else if (curSum < target) {
                    ++begin;
                    while(nums[begin] == nums[begin-1]) {
                        ++begin;
                    }
                } else {
                    --end;
                    while(nums[end] == nums[end+1]) {
                        --end;
                    }
                }
            }
           }
        }
        return result;
    }
};
