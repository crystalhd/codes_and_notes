/*
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-06-02 00:46
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size < 3) {
            return 0;
        }
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == candidate1) {
                ++count1; 
                continue;
            }
            if (nums[i] == candidate2) {
                ++count2;
                continue;
            }
            if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        int check1 = 0; 
        int check2 = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == candidate1) {
                ++check1;
            }
            if (nums[i] == candidate2) {
                ++check2;
            }
        }
        return check1 > check2 ? candidate1 : candidate2;
    }
};
