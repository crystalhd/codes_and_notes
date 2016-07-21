/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-06-04 21:28
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int dif(int num1, int num2) {
        return num1 >= num2 ? num1 - num2 : num2 - num1;
    }
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        if (nums.size() < 3) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int begin = i + 1;
            int end = nums.size() - 1;
            if (begin >= nums.size() || begin == end) {
                return sum;
            }
            while (begin < end) {
                int curSum = nums[i] + nums[begin] + nums[end];
                if (curSum == target) {
                    return target;
                }
                else if (curSum < target) {
                    if ((target - curSum) < diff) {
                        sum = curSum;
                        diff = target - curSum;
                    }
                    ++begin;
                   while (begin<nums.size()-1 && nums[begin] == nums[begin-1]) {
                        ++begin;
                    }
                }
               // tmpSum1 = curSum;
                else {
                    if ((curSum - target) < diff) {
                        sum = curSum;
                        diff = curSum - target;
                    }
                    --end;
                    while(end>0 && nums[end] == nums[end+1]) {
                        --end;
                    }       
                }
            }
           
        }
        return sum;
    }
    
};
