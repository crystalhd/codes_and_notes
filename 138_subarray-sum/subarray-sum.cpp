/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-06-03 17:26
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> result;
        if (nums.size() == 0) return result;
        unordered_map<int, int> record;
        record[0] = -1;
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (record.find(curSum) != record.end()) {
                result.push_back(record[curSum]+1);
                result.push_back(i);
                return result;
            }
            record[curSum] = i;
        }
        return result;
    }
};